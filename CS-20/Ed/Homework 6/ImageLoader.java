import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import javax.imageio.ImageIO;

/**
 * A simple class for loading images from files and JARs.
 *
 * @author Ed Parrish
 * @version 1.0  02/05/06
 */
public class ImageLoader {
    private GraphicsConfiguration gc;

    /**
     * Constructs an ImageLoader with a default GraphicsConfiguration
     */
    public ImageLoader() {
        gc = GraphicsEnvironment
            .getLocalGraphicsEnvironment()
            .getDefaultScreenDevice()
            .getDefaultConfiguration();
    }

    /**
     * Load a BufferedImage compatible with the GraphicsConfiguration
     *
     * @param fileName The name and path to the file.
     * @return A compatible BufferedImage.
     */
    public BufferedImage loadImage(String fileName) {
        BufferedImage im = null;
        try {
            im = ImageIO.read(getClass().getResource(fileName));
            int w = im.getWidth();
            int h = im.getHeight();
            int t = im.getColorModel().getTransparency();

            BufferedImage copy = gc.createCompatibleImage(w, h, t);
            Graphics2D g2 = copy.createGraphics();
            g2.drawImage(im, 0, 0, null);
            g2.dispose();
            return copy;
        } catch (IllegalArgumentException e) {
            System.out.println("Cannot find: " + fileName);
            return null;
        } catch (IOException e) {
            System.out.println("Error loading: " + fileName);
            return null;
        }
    }
}