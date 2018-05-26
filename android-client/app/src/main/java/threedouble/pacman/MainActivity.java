package threedouble.pacman;

import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.ConfigurationInfo;
import android.opengl.GLSurfaceView;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.support.v7.app.AppCompatActivity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.io.IOException;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;


public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("game");
    }

    public boolean isProbablyEmulator() {
        return Build.VERSION.SDK_INT >= Build.VERSION_CODES.ICE_CREAM_SANDWICH_MR1
                && (Build.FINGERPRINT.startsWith("generic")
                || Build.FINGERPRINT.startsWith("unknown")
                || Build.MODEL.contains("google_sdk")
                || Build.MODEL.contains("Emulator")
                || Build.MODEL.contains("Android S3cDK built for x86"));
    }

    public static Handler messageHandler;
    public static Handler viewHandler;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // remove title
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);
        setContentView(R.layout.activity_main);

        ActivityManager activityManager
                = (ActivityManager) getSystemService(Context.ACTIVITY_SERVICE);
        ConfigurationInfo configurationInfo = activityManager.getDeviceConfigurationInfo();

        if (!(configurationInfo.reqGlEsVersion >= 0x20000) && !isProbablyEmulator()) {
            Toast.makeText(this, "This device does not support OpenGL ES 2.0.",
                    Toast.LENGTH_LONG).show();
            return;
        }

        setContentView(R.layout.activity_main);
        final Button button = findViewById(R.id.button);
        final EditText usernameField = findViewById(R.id.username_field);
        final EditText ipAddresField = findViewById(R.id.ipaddres_field);
        final TextView messageField = findViewById(R.id.message_label);


        button.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                String username = usernameField.getText().toString();
                try {
                    if (!username.isEmpty()) {
                        game.start(username, InetAddress.getByName(ipAddresField.getText().toString()));
                    } else {
                        messageField.setText(R.string.exception_enter_username);
                    }
                } catch (IOException e) {
                    messageField.setText(e.toString());
                }
            }
        });

        messageHandler = new Handler(){
            @Override
            public void handleMessage(Message msg) {
                messageField.setText((String)msg.obj);
                super.handleMessage(msg);
            }
        };

        viewHandler = new Handler(){
            @Override
            public void handleMessage(Message msg) {
                setContentView((View) msg.obj);
                super.handleMessage(msg);
            }
        };

        try {
            game = new Game(this);
        } catch (SocketException e) {
            messageField.setText(e.toString());
        }
    }

    @Override
    protected void onPause() {
        super.onPause();

        if (game.isRendererSet()) {
            game.getGLSurfaceView().onPause();
        }
    }

    @Override
    protected void onResume() {
        super.onResume();

        if (game.isRendererSet()) {
            game.getGLSurfaceView().onResume();
        }
    }

//    private TextView messageField;
    private Game game;
}
