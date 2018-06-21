package threedouble.pacman;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class EndGameActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_end_game);


        Intent intent = getIntent();

        String gameOverString = intent.getStringExtra("game_over_text");
        TextView gameOverText = findViewById(R.id.game_over);
        gameOverText.setText(gameOverString);

        String pointString = intent.getStringExtra("point_text");
        TextView pointText = findViewById(R.id.points);
        pointText.setText(pointString);
    }
}
