import java.awt.*;
import java.awt.geom.AffineTransform;
import java.io.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.net.*;
import java.util.*;
	

public class ResourceManager {

	private int currentMap;
	private GraphicsConfiguration gc;
	private ImageLoader loader;
	
	
	public ResourceManager(GraphicsConfiguration gc)	{
		this.gc = gc;
	}
	
	
	public TileMap loadFirstMap()	{
		currentMap = 0;
		return loadNextMap();
	}
	
	public TileMap loadNextMap()	{
		TileMap map = null;
		while (map == null)	{
			currentMap++;
			try	{
				map = loadMap("Maps/Map" + currentMap + ".txt");
			}
			catch (IOException ex)	{
				if (currentMap == 1)	{
					return null;
				}
				currentMap = 0;
				map = null;
			}
		}
		return map;
	}
	
	public TileMap reloadMap()	{
		try	{
			return loadMap("Maps/Map" + currentMap + ".txt");
		}
		catch (IOException ex)	{
			ex.printStackTrace();
			return null;
		}
	}

	private TileMap loadMap(String filename) throws IOException	{
		ArrayList<String> lines = new ArrayList<String>();
		BufferedReader reader;
		
		try {
            ClassLoader classLoader = getClass().getClassLoader();
            URL url = classLoader.getResource(filename);
			if (url == null)	{
				throw new IOException("No such map:" + filename);
			}
			reader = new BufferedReader(new InputStreamReader(url.openStream()));
            
        } catch (Exception e) {
			throw new IOException();
        }
		
		TileMap newMap = new TileMap();
        newMap.setPlayer(new PlayerSprite());
		
		while (true)	{
			String line = reader.readLine();
			if (line == null)	{
				reader.close();
				break;
			}   else if (line.startsWith("Wall"))  {
                Point first = new Point();
                Point second = new Point();
                
                int firstComma = line.indexOf(",");
                int secondComma = line.indexOf(",", firstComma + 1);
                int thirdComma = line.indexOf(",", secondComma + 1);
                int fourthComma = line.indexOf(",", thirdComma + 1);
                
                String x1 = line.substring(line.indexOf("(") + 1, firstComma);
                String y1 = line.substring(firstComma + 2, secondComma);
                String x2 = line.substring(secondComma + 2, thirdComma);
                String y2 = line.substring(thirdComma + 2, fourthComma);
                String color = line.substring(fourthComma + 2, line.length() - 1);
                
                Color c =  new Color(0.0f, 1.0f, 0.0f);
                if (color.equals("red"))   {
                    c = Color.red;
                }
                
                Wall wall = new Wall(Integer.parseInt(x1), Integer.parseInt(y1),
                                     Integer.parseInt(x2), Integer.parseInt(y2), c);
                                     
                addSprite(newMap, wall);
            }
        }
        return newMap;
	}
	
	
	private void addSprite(TileMap map, Sprite sprite)	{
        map.addSprite(sprite);
	}
}
