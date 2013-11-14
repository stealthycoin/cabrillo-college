import java.awt.*;
import javax.swing.JFrame;

public class RunnerFullScreen extends GameManager {
    private static final int REFRESH_RATE =
        DisplayMode.REFRESH_RATE_UNKNOWN;
    private static final DisplayMode POSSIBLE_MODES[] = {
        new DisplayMode(800, 600, 32, REFRESH_RATE),
        new DisplayMode(800, 600, 24, REFRESH_RATE),
        new DisplayMode(800, 600, 16, REFRESH_RATE),
        new DisplayMode(640, 480, 32, REFRESH_RATE),
        new DisplayMode(640, 480, 24, REFRESH_RATE),
        new DisplayMode(640, 480, 16, REFRESH_RATE),
    };
    private ScreenManager screen;

    // Driver to start the game
    public static void main(String[] args) {
        RunnerFullScreen canvas = new RunnerFullScreen();
        canvas.start();
    }

    // Set full-screen mode and start game
    public void start() {
        screen = new ScreenManager();
        DisplayMode displayMode =
            screen.findFirstCompatibleMode(POSSIBLE_MODES);
        screen.setFullScreen(displayMode);

        // Add canvas after entering FSEM and changing mode
        JFrame frame = screen.getFullScreenWindow();
        frame.add(this);  // add components
        frame.validate(); // layout components

        init();
        startGame();
    }

    // Override superclass to restore the screen
    public void exitGame() {
        screen.restoreScreen();
        super.exitGame();
    }
}