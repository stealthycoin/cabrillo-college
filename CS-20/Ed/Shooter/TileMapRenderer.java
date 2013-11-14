import java.awt.*;
import java.util.Iterator;
import java.awt.image.BufferedImage;

/**
    The TileMapRenderer class draws a TileMap on the screen.
    It draws all tiles, sprites, and an optional background image
    centered around the position of the player.

    <p>If the width of background image is smaller the width of
    the tile map, the background image will appear to move
    slowly, creating a parallax background effect.

    <p>Also, three static methods are provided to convert pixels
    to tile positions, and vice-versa.

    <p>This TileMapRender uses a tile size of 32.
*/
public class TileMapRenderer {

    private static final int TILE_SIZE = 32;
    // the size in bits of the tile
    // Math.pow(2, TILE_SIZE_BITS) == TILE_SIZE
    private static final int TILE_SIZE_BITS = 5;

    private BufferedImage background;


	//Converts a pixel position to a tile position.
	
    public static int pixelsToTiles(float pixels) {
        return pixelsToTiles(Math.round(pixels));
    }


	//Converts a pixel position to a tile position.
    public static int pixelsToTiles(int pixels) {
        // use shifting to get correct values for negative pixels
        return pixels >> TILE_SIZE_BITS;

        // or, for tile sizes that aren't a power of two,
        // use the floor function:
        //return (int)Math.floor((float)pixels / TILE_SIZE);
    }


    //Converts a tile position to a pixel position.
    public static int tilesToPixels(int numTiles) {
        return numTiles << TILE_SIZE_BITS;

        // use this if the tile size isn't a power of 2:
        //return numTiles * TILE_SIZE;
    }


	//Sets the background to draw.
    public void setBackground(BufferedImage background) {
        this.background = background;
    }


    
	//Draws the specified TileMap.
    
    public void draw(Graphics2D g, TileMap map,
        int screenWidth, int screenHeight)
    {
		ImageSFXs sfx = new ImageSFXs();
        Sprite player = map.getPlayer();

        g.setColor(Color.black);
        g.fillRect(0, 0, screenWidth, screenHeight);
            
        //draw player
        g.setColor(Color.red);
        player.draw(g);
        
        // draw sprites
        Iterator i = map.getSprites();
        while (i.hasNext()) {
            Sprite sprite = (Sprite)i.next();
            sprite.draw(g);
        }
    }

}