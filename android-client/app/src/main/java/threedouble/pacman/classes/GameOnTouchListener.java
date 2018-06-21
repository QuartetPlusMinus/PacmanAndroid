package threedouble.pacman.classes;

import android.view.MotionEvent;
import android.view.View;

import java.io.IOException;

public class GameOnTouchListener implements View.OnTouchListener{

    public GameOnTouchListener(Server server) {
        this.server = server;
    }

    @Override
    public boolean onTouch(View view, MotionEvent event) {
        view.performClick();

        if (event == null)
            return false;

        switch (event.getAction()) {
            case MotionEvent.ACTION_DOWN:
                onTouchX = event.getX();
                onTouchY = event.getY();
                break;
            case MotionEvent.ACTION_MOVE:
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
//                    Toast.makeText(this, e.toString(), Toast.LENGTH_LONG).show();
                }
        }
        return true;
    }

    private float onTouchX;
    private float onTouchY;
    private Server server;
}
