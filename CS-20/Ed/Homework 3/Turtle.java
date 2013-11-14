import java.awt.*;
import java.awt.geom.*;

/**
 * Implements a logo-style turtle. The turtle starts centered in its world
 * and  facing up (north). Up is a heading of 0 (zero) degrees.
 * <p>A turtle has a pen, which leaves a track (line) behind it when the
 * pen is down, and no track when the pen is up. You control the turtle
 * by calling the methods of this Turtle class.
 * <p>For example, to create a turtle and draw a line 50 pixels long:
 * <pre>
 * Turtle myrtle = new Turtle();
 * myrtle.forward(50);
 * </pre>
 *
 * @author Ed Parrish
 * @version 1.0  06/17/06
 */
public class Turtle {
    public static final Color DEFAULT_TURTLE_COLOR = Color.GREEN;
    public static final int TURTLE_SIZE = 10;
    public static final int TURTLE_HALF_SIZE = TURTLE_SIZE / 2;

    private double heading = 0;  // default is facing north
    private int posX, posY;
    private boolean visible = true;

    private Pen pen = new Pen();
    private World world;

    /**
     * Constructs a Turtle object and a World to live within.
     */
    public Turtle() {
        world = new World();
        world.setTurtle(this);
        center();
    }

    /**
     * Constructs a Turtle object and adds itself to the given World.
     *
     * @param world The World in which this Turtle lives.
     */
    public Turtle(World world) {
        this.world = world;
        world.setTurtle(this);
        center();
    }

    /**
     * Move this turtle forward the given number of pixels in the direction
     * it is heading.
     *
     * @param pixels The number of pixels to move forward.
     */
    public void forward(int pixels) {
        int x = posX + (int) (pixels * Math.sin(Math.toRadians(heading)));
        int y = posY + (int) (pixels * -Math.cos(Math.toRadians(heading)));
        moveTo(x, y);
    }

    /**
     * Move this turtle backward the given number of pixels from the direction
     * it is heading.
     *
     * @param pixels The number of pixels to move backward.
     */
    public void backward(int pixels) { forward(-pixels); }

    /**
     * Move this turtle to the center of its world.
     *
     * The turtle moves without drawing.
     */
    public void center() {
        posX = world.getWidth() / 2;
        posY = world.getHeight() / 2;
    }

    /**
     * Move this turtle to the given x and y location.
     *
     * @param x The x-coordinate to move this Turtle to.
     * @param y The y-coordinate to move this Turtle to.
     */
    public void moveTo(int x, int y) {
        if (x < 0) x = 0;
        if (y < 0) y = 0;
        if (x >= world.getWidth()) x = world.getWidth() - 1;
        if (y >= world.getHeight()) y = world.getHeight() - 1;

        pen.addMove(posX, posY, x, y);
        posX = x;
        posY = y;
        world.repaint();
    }

    /**
     * Turn this turtle to the right (clockwise) the given number of degrees
     * from the current direction it is heading.
     *
     * @param degrees The number of degrees to turn.
     */
    public void right(double degrees) {
        heading = (heading + degrees) % 360;
        world.repaint();
    }

    /**
     * Turn this turtle to the left (counter-clockwise) the given number
     * of degrees from the current direction it is heading.
     *
     * @param degrees The number of degrees to turn.
     */
    public void left(double degrees) { right(-degrees); }

    /**
     * Turn this turtle to the given heading (direction).
     *
     * <p>Headings are based on the degrees of the compass with zero (0)
     * degrees meaning to point straight up and turning clockwise through
     * 360 degrees.
     *
     * @param degrees The new heading for this Turtle.
     */
    public void setHeading(double degrees) { heading = degrees % 360; }

    /**
     * Returns the current heading (direction) in degrees for this turtle.
     *
     * @return The current heading in degrees.
     */
    public double getHeading() { return heading; }

    /**
     * Hide this turtle so it does not display itself in its world. Note
     * that this method does not affect the pen lines.
     */
    public void hide() { setVisible(false); }

    /**
     * Show this turtle so that it displays itself in its world. Note
     * that this method does not affect the pen lines.
     */
    public void show() { setVisible(true); }

    /**
     * Checks whether this turtle is visible.
     *
     * @return <code>true</code> if this turtle is visible else
     * <code>false</code>.
     */
    public boolean isVisible() { return visible; }

    /**
     * Controls whether or not to display this turtle in its world. Note
     * that this method does not affect the pen lines.
     *
     * @param visibilityFlag Use <code>true</code> to make this turtle
     * visible, otherwise use <code>false</code>.
     */
    public void setVisible(boolean visibilityFlag) {
        visible = visibilityFlag;
        if (visible == false && visibilityFlag == true) {
            world.repaint();
        }
    }

    /**
     * Checks whether the pen is down for this turtle.
     *
     * @return <code>true</code> if the pen is down else <code>false</code>.
     */
    public boolean isPenDown() { return pen.isPointDown(); }

    /**
     * Sets the point of the pen down to that the turtle starts recording
     * its travel.
     */
    public void penDown() { pen.setPointDown(true); }

    /**
     * Lifts the point of the pen up to that the turtle stops recording
     * its travel.
     */
    public void penUp() { pen.setPointDown(false); }

    /**
     * Removes all the lines drawn by the pen of this turtle.
     */
    public void clear() {
        pen.clear();
        world.repaint();
    }

    /**
     * Returns the current color of the pen with which this turtle is drawing.
     *
     * @return The pen color of this turtle.
     */
    public Color getPenColor() { return pen.getColor(); }

    /**
     * Changes the pen color of this turtle.
     *
     * @param newColor The new color with which to start drawing.
     */
    public void setPenColor(Color newColor) { pen.setColor(newColor); }

    /**
     * Returns the current width of the pen with which this turtle is drawing.
     *
     * @return The pen width of this turtle.
     */
    public int getPenWidth() { return pen.getWidth(); }

    /**
     * Changes the width of the line with which that this turtle draws.
     *
     * @param newWidth The new pen width with which to start drawing.
     */
    public void setPenWidth(int newWidth) { pen.setWidth(newWidth); }

    /**
     * Returns the current world in which this turtle lives.
     *
     * @return The world in which this turtle lives.
     */
    public World getWorld() { return world; }

    /**
     * Returns the background color of the world in which this turtle lives.
     *
     * @return The color of the world in which this turtle lives.
     */
    public Color getWorldBackground() { return world.getBackground(); }

    /**
     * Changes the color of the world in which this turtle lives.
     *
     * @param newColor The new background color for the world of this turtle.
     */
    public void setWorldBackground(Color newColor) {
        world.setBackground(newColor);
    }

    /**
     * Puts this turtle to sleep (stops it from running) for the given
     * number of milliseconds.
     *
     * @param milliseconds The length of time for this turtle to sleep.
     */
    public void sleep(int milliseconds) {
        try {
            Thread.sleep(milliseconds);
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted!");
            e.printStackTrace();
            System.exit(1);
        }
    }

    /**
     * Draw all the pen lines and, if set to visible, this turtle as well.
     *
     * @param g2 The graphics context to use for drawing.
     */
    public void draw(Graphics2D g2) {
        pen.draw(g2);
        if (visible) {
            AffineTransform oldTransform = g2.getTransform();
            g2.rotate(Math.toRadians(heading), posX, posY);

            GeneralPath triangle = new GeneralPath();
            triangle.moveTo(posX, posY - TURTLE_SIZE);
            triangle.lineTo(posX - TURTLE_HALF_SIZE, posY);
            triangle.lineTo(posX + TURTLE_HALF_SIZE, posY);
            triangle.lineTo(posX, posY - TURTLE_SIZE);
            g2.setColor(pen.getColor());
            g2.fill(triangle);
            g2.draw(triangle);

            g2.setTransform(oldTransform);
        }
    }
}
