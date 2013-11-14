import java.awt.*;
import javax.swing.*;

/**
 * A World is a rectangular area in which a Turtle can live.
 *
 * @author Ed Parrish
 * @version 1.0  06/17/06
 */
public class World extends JComponent {
    public static final int WIDTH = 640, HEIGHT = 640;

    private JFrame frame;
    private Turtle turtle;

    /**
     * Constructor sets up the turtle world.
     */
    public World() {
        setBackground(Color.WHITE);
        setPreferredSize(new Dimension(WIDTH, HEIGHT));
        frame = new JFrame("Turtle World");
        frame.setDefaultCloseOperation(frame.EXIT_ON_CLOSE);
        frame.add(this);
        frame.pack();
        frame.setVisible(true);
    }

    /**
     * Makes <code>newTurtle</code> the inhabitant of this world.
     *
     * @param newTurtle a turtle to inhabit this World.
     */
    public void setTurtle(Turtle newTurtle) {
        turtle = newTurtle;
    }

    /**
     * Paints this world with the background color and any turtle.
     *
     * @param g The graphics context to use for drawing.
     */
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(getBackground());
        g.fillRect(0, 0, getWidth(), getHeight());
        if (turtle != null) {
            Graphics2D g2 = (Graphics2D) g;
            turtle.draw(g2);
        }
    }

    /**
     * Controls whether or not to display this world and its frame.
     *
     * @param visibilityFlag Use <code>true</code> to make this world
     * visible, otherwise use <code>false</code>.
     */
    public void setVisible(boolean visibilityFlag) {
        frame.setVisible(visibilityFlag);
    }
}
