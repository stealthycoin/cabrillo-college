import java.awt.*;
import java.awt.geom.*;
import java.util.*;

/**
 * The <code>Pen</code> class implements a simple pen for writing lines.
 *
 * @author Ed Parrish
 * @version 1.0  06/17/06
 */
public class Pen {
    private Color color = Color.BLACK;
    private boolean pointDown = true;
    private int width = 1;
    private java.util.List<LineSegment> lineList =
        Collections.synchronizedList(new ArrayList<LineSegment>());

    /**
     * Constructs a Pen with default values.
     */
    public Pen() { }

    /**
     * Add a line segment if the point of this pen is down.
     *
     * @param x1 The from x-coordinate
     * @param y1 The from y-coordinate
     * @param x2 The to x-coordinate
     * @param y2 The to y-coordinate
     */
    public void addMove(int x1, int y1, int x2, int y2) {
        if (pointDown) {
            LineSegment seg = new LineSegment(color, width,
                new Line2D.Float(x1, y1, x2, y2));
            lineList.add(seg);
        }
    }

    /**
     * Remove all the lines drawn by this Pen.
     */
    public void clear() { lineList.clear(); }

    /**
     * Return the current color of this Pen.
     *
     * @return The current color of this Pen.
     */
    public Color getColor() { return color; }

    /**
     * Set the color with which to draw.
     *
     * @param newColor The new color to use.
     */
    public void setColor(Color newColor) { color = newColor; }

    /**
     * Checks whether the point of this pen is down.
     *
     * @return <code>true</code> if down else <code>false</code>.
     */
    public boolean isPointDown() { return pointDown; }

    /**
     * Set the point of the pen down to start writing.
     *
     * @param downState Use <code>true</code> to set the point of this pen
     * down, otherwise use <code>false</code>.
     */
    public void setPointDown(boolean downState) { pointDown = downState; }

    /**
     * Return the current width of the stroke width of this Pen.
     *
     * @return The current stroke width of this Pen.
     */
    public int getWidth() { return width; }

    /**
     * Set the stroke width with which this pen writes.
     *
     * @param newWidth The new stroke width in pixels.
     */
    public void setWidth(int newWidth) { width = newWidth; }

    /**
     * Draw all the pen lines recorded so far.
     *
     * @param g2 The graphics context to use for drawing.
     */
    public void draw(Graphics2D g2) {
        synchronized(lineList) {
            Iterator iterator = lineList.iterator();
            LineSegment seg = null;

            while (iterator.hasNext()) {
                seg = (LineSegment) iterator.next();
                seg.draw(g2);
            }
        }
    }

    /**
     * Implements a line for writing with length, width and color.
     */
    private class LineSegment {
        private Color color;
        private int width;
        private Line2D.Float line;

        /**
         * Constructor for a line segment.
         *
         * @param newColor The color of this LineSegment.
         * @param newWidth The width of this LineSegment.
         * @param newLine The line of this LineSegment.
         */
        public LineSegment (Color newColor, int newWidth,
                Line2D.Float newLine) {
            color = newColor;
            width = newWidth;
            line = newLine;
        }

        /**
         * Draw this line segment on the graphics context.
         *
         * @param g2 The Graphics2D context
         */
        public void draw(Graphics2D g2) {
            BasicStroke stroke = new BasicStroke(width);
            g2.setStroke(stroke);
            g2.setColor(color);
            g2.draw(line);
        }
    }
}
