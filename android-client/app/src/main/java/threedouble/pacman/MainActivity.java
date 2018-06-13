package threedouble.pacman;

import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.ConfigurationInfo;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.support.v7.app.AppCompatActivity;
import android.view.MotionEvent;
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

public class MainActivity extends AppCompatActivity implements View.OnTouchListener {
    static {
        System.loadLibrary("game");
    }

    public boolean isProbablyEmulator() {
        return (Build.FINGERPRINT.startsWith("generic")
                || Build.FINGERPRINT.startsWith("unknown")
                || Build.MODEL.contains("google_sdk")
                || Build.MODEL.contains("Emulator")
                || Build.MODEL.contains("Android S3cDK built for x86"));
    }

    public Handler messageHandler;

    static class MessageHandler extends Handler {
        MessageHandler(TextView messageField) {
            super();
            this.messageField = messageField;
        }

        @Override
        public void handleMessage(Message msg) {
            messageField.setText((String) msg.obj);
            super.handleMessage(msg);
        }

        private final TextView messageField;
    }

    public Handler viewHandler;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_main);

        ActivityManager activityManager
                = (ActivityManager) getSystemService(Context.ACTIVITY_SERVICE);

        ConfigurationInfo configurationInfo;

        if (activityManager == null) {
            Toast.makeText(this, "Activity Manager is not available",
                    Toast.LENGTH_LONG).show();
            return;
        }
        configurationInfo = activityManager.getDeviceConfigurationInfo();


        if (!(configurationInfo.reqGlEsVersion >= 0x20000) && !isProbablyEmulator()) {
            Toast.makeText(this, "This device does not support OpenGL ES 2.0.",
                    Toast.LENGTH_LONG).show();
            return;
        }

        setContentView(R.layout.activity_main);
        final Button button = findViewById(R.id.button);
        final EditText usernameField = findViewById(R.id.username_field);
        final EditText ipAddressField = findViewById(R.id.ipaddress_field);
        final TextView messageField = findViewById(R.id.message_label);


        button.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                String username = usernameField.getText().toString();
                try {
                    if (!username.isEmpty()) {
                        server = new Server(InetAddress.getByName(ipAddressField.getText().toString()), PORT, game.getSocket());
                        game.start(username);
                    } else {
                        messageField.setText(R.string.exception_enter_username);
                    }
                } catch (IOException e) {
                    messageField.setText(e.toString());
                }
            }
        });

        messageHandler = new MessageHandler(messageField);

        viewHandler = new Handler() {
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

    @Override
    public boolean onTouch(View view, MotionEvent event) {
        switch (event.getAction()) {
            case MotionEvent.ACTION_DOWN:
                onTouchX = event.getX();
                onTouchY = event.getY();
                break;
            case MotionEvent.ACTION_UP:
            case MotionEvent.ACTION_CANCEL:
                float xMove = Math.abs(onTouchX - event.getX());
                float yMove = Math.abs(onTouchY - event.getY());
                if (xMove < 0.1 && yMove < 0.1)
                    break;
                try {
                    if (xMove > yMove) {
                        if (onTouchX < event.getX()) {
                            server.Event(Direction.RIGHT);
                        } else {
                            server.Event(Direction.LEFT);
                        }
                    } else {
                        if (onTouchY < event.getY()) {
                            server.Event(Direction.DOWN);
                        } else {
                            server.Event(Direction.UP);
                        }
                    }
                } catch (IOException e) {
                    Toast.makeText(this, e.toString(),
                            Toast.LENGTH_LONG).show();
                }
        }
        return view.performClick();
    }

    public Server server;
    private Game game;
    private float onTouchX;
    private float onTouchY;
    static private final int PORT = 31415;

}
