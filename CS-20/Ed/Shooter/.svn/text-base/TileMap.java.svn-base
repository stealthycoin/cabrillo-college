import java.awt.image.BufferedImage;
import java.util.LinkedList;
import java.util.Iterator;
import java.awt.*;


public class TileMap {
	private LinkedList<Sprite> sprites;
	private PlayerSprite player;
	
	
	public TileMap()	{
        player = new PlayerSprite();
        
        sprites = new LinkedList<Sprite>();
	}
		
	//the player in Sprite form, have to cast to get a PlayerSprite
	public Sprite getPlayer()	{
		return player;
	}
	
	public void setPlayer(PlayerSprite player)	{
		this.player = player;
	}
	
	public void addSprite(Sprite sprite)	{
		sprites.add(sprite);
	}
	
	public void removeSprite(Sprite sprite)	{
		sprites.remove(sprite);
	}
	
	public Iterator getSprites()	{
		return sprites.iterator();
	}
}