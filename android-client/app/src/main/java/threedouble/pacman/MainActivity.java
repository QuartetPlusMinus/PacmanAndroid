package threedouble.pacman;

import android.annotation.SuppressLint;
import android.app.ActivityManager;
import android.content.Context;
import android.content.Intent;
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

import threedouble.pacman.classes.Game;
import threedouble.pacman.classes.GameOnTouchListener;
import threedouble.pacman.classes.GameRenderer;
import threedouble.pacman.classes.Server;

public class MainActivity extends AppCompatActivity {
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

    public Handler startHandler;

    static class StartHandler extends Handler {
        StartHandler(MainActivity context) {
            this.context = context;
        }

        @Override
        public void handleMessage(Message msg) {
            GLSurfaceView glSurfaceView = new GLSurfaceView(context);
            context.setGLSurfaceView(glSurfaceView);

            if (context.isProbablyEmulator()) {
                glSurfaceView.setEGLConfigChooser(8, 8, 8, 8, 16, 0);
            }

            glSurfaceView.setEGLContextClientVersion(2);
            GameRenderer gameRenderer = new GameRenderer(context.getAssets(), (byte[])msg.obj);
            glSurfaceView.setRenderer(gameRenderer);
            glSurfaceView.setOnTouchListener(new GameOnTouchListener(context.server));

            context.setContentView(glSurfaceView);
            super.handleMessage(msg);
        }

        MainActivity context;
    }

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

        startHandler = new StartHandler(this);

        try {
            game = new Game(this);
        } catch (SocketException e) {
            messageField.setText(e.toString());
        }
    }

    public void setGLSurfaceView(GLSurfaceView glSurfaceView) {
        this.glSurfaceView = glSurfaceView;
    }

    @Override
    protected void onPause() {
        super.onPause();

        if (glSurfaceView != null) {
            glSurfaceView.onPause();
        }
    }

    @Override
    protected void onResume() {
        super.onResume();

        if (glSurfaceView != null) {
            glSurfaceView.onResume();
        }
    }

    @SuppressLint("SetTextI18n")
    public void endGame() {
        Intent intent = new Intent(this, EndGameActivity.class);
        intent.putExtra("game_over_text", "You Lose");
        intent.putExtra("point_text", "777");
        startActivity(intent);
    }

    public Server server;
    private Game game;
    private GLSurfaceView glSurfaceView;
    static private final int PORT = 31415;
}
