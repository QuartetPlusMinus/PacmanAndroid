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
import android.view.View;
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

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

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
        final TextView messageField = findViewById(R.id.message_label);
        final EditText usernameField = findViewById(R.id.username_field);

        final Handler messageHandler = new Handler(){
            @Override
            public void handleMessage(Message msg) {
                messageField.setText((String)msg.obj);
                super.handleMessage(msg);
            }
        };

        button.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                String username = usernameField.getText().toString();
                try {
                    if (!username.isEmpty()) {
                        game.start(username);
                    } else {
                        messageField.setText(R.string.exception_enter_username);
                    }
                } catch (IOException e) {
                    messageField.setText(e.toString());
                }
            }
        });

        try {
            game = new Game(InetAddress.getByName("192.168.43.86"), this, messageHandler); // machine localhost
//            game = new Game(InetAddress.getByName("10.0.2.2"), this); // machine localhost
        } catch (UnknownHostException e) {
            messageField.setText(e.toString());
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

    private Game game;
}
