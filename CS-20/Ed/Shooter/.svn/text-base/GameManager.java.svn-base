import java.awt.*;
import java.awt.image.BufferedImage;
import java.awt.event.*;
import java.util.*;
import java.io.*;
import javax.swing.*;
import javax.swing.border.*;
import javax.sound.sampled.AudioFormat;
import javax.sound.midi.*;
import java.awt.geom.*;

import java.io.*;
import javax.sound.sampled.*;
import java.text.DecimalFormat;
import java.net.URL;

public class GameManager extends GameCanvas {
    public static final int RIGHT_ANGLE = 90;
    private int fps;          // frames per second
	private ResourceManager resourceManager;
    private TileMap map;
    private TileMapRenderer render;
    private KeyState keys;
    
    
    public void init() {
        addKeyListener(new KeyHandler());
        keys = new KeyState();
        render = new TileMapRenderer();
        resourceManager = new ResourceManager(GraphicsEnvironment
            .getLocalGraphicsEnvironment()
            .getDefaultScreenDevice()
            .getDefaultConfiguration());
        map = resourceManager.loadFirstMap();
    }
    
    public void fire(float x, float y, float dx, float dy, Color c, float size)  {
        Projectile p = new Projectile(x, y, dx, dy, c, size);
        map.addSprite(p);
    } 
    
    public void checkInput(PlayerSprite player, long elapsedTime)    {
        if (keys.space())   {
            if (player.canFire)   {
                Vector v = new Vector((float)Math.cos(Math.toRadians(player.getAngle() - RIGHT_ANGLE)),
                                      (float)Math.sin(Math.toRadians(player.getAngle() - RIGHT_ANGLE)));
                v = Vector.normalize(v);
                v.x *= Projectile.SPEED;
                v.y *= Projectile.SPEED;
                fire(player.getX(), player.getY(), v.x, v.y, player.getColor(), player.getSize() / 3.0f);
                player.canFire = false;
            }
        }
        
        if (keys.w())   {
            player.setVelocityY(-PlayerSprite.SPEED);
        }
        else    {
            player.setVelocityY(0);
        }
        if (keys.s())   {
            player.setVelocityY(PlayerSprite.SPEED);   
        }
        if (keys.d())   {
            player.setVelocityX(PlayerSprite.SPEED);
        }
        else    {
            player.setVelocityX(0);
        }
        if (keys.a())   {
            player.setVelocityX(-PlayerSprite.SPEED);
        }
        
        //rotation
        if (keys.left())   {
            player.setAngle(player.getAngle() - PlayerSprite.ROTATION * elapsedTime);
        }
        if (keys.right())   {
            player.setAngle(player.getAngle() + PlayerSprite.ROTATION * elapsedTime);
        }
        if (keys.up())   {
            player.setVelocityX((float)Math.cos(Math.toRadians(player.getAngle() - RIGHT_ANGLE)));
            player.setVelocityY((float)Math.sin(Math.toRadians(player.getAngle() - RIGHT_ANGLE)));
            
            Vector velocity = new Vector(player.getVelocityX(), player.getVelocityY());
            velocity = Vector.normalize(velocity);
            
            player.setVelocityX(velocity.x * PlayerSprite.SPEED);
            player.setVelocityY(velocity.y * PlayerSprite.SPEED);
        }
        if (keys.down())   {
            player.setVelocityX((float)-Math.cos(Math.toRadians(player.getAngle() - RIGHT_ANGLE)));
            player.setVelocityY((float)-Math.sin(Math.toRadians(player.getAngle() - RIGHT_ANGLE)));
            
            Vector velocity = new Vector(player.getVelocityX(), player.getVelocityY());
            velocity = Vector.normalize(velocity);
            
            player.setVelocityX(velocity.x * PlayerSprite.SPEED);
            player.setVelocityY(velocity.y * PlayerSprite.SPEED);
        }
    }
    
    /**
        Chekcs to see if sp is in bounds
        
        @param sp is sp in bounds?
        @param x sp's x to be
        @param y sp's y to be
        @return boolean yes if it is no if it isn't
    */
    public boolean inBounds(Sprite sp, float x, float y)   {
        float halfSize = sp.getSize() / 2.0f;
        Vector tl = new Vector(x - halfSize, y - halfSize);
        Vector tr = new Vector(x + halfSize, y - halfSize);
        Vector bl = new Vector(x - halfSize, y + halfSize);
        Vector br = new Vector(x + halfSize, y + halfSize);
        
        if (tl.x < 0 || tl.y < 0 ||
            tr.x < 0 || tr.y < 0 ||
            bl.x < 0 || bl.y < 0 ||
            br.x < 0 || br.y < 0)   {
            return false;
        }
        if (tl.x > RunnerApp.WIDTH || tl.y > RunnerApp.HEIGHT ||
            tr.x > RunnerApp.WIDTH || tr.y > RunnerApp.HEIGHT ||
            bl.x > RunnerApp.WIDTH || bl.y > RunnerApp.HEIGHT ||
            br.x > RunnerApp.WIDTH || br.y > RunnerApp.HEIGHT)   {
            return false;
        }
        return true;
    }
    
    public boolean spriteIsTouchingSprite(Sprite s1, Sprite s2)    {
        Polygon r1 = s1.getPolygon();
        Rectangle r2 = s2.getBounds();
        if (r1.contains(r2))   {
            return true;
        }
        return false;
    }
    
    public void updateSprite(Sprite sprite, long elaspedTime, LinkedList<Sprite> tr) {
        float oldX = sprite.getX();
        float newX = oldX + sprite.getVelocityX() * elaspedTime;
        float oldY = sprite.getY();
        float newY = oldY + sprite.getVelocityY() * elaspedTime;
        
        if (inBounds(sprite, newX, newY))   {
            sprite.setX(newX);
            sprite.setY(newY);
        }   else    {
            if (sprite instanceof Projectile)   {
                tr.add(sprite);
            }
        }
        
        Iterator i = map.getSprites();
        while (i.hasNext())    {
            Sprite sp = (Sprite)i.next();
            if (spriteIsTouchingSprite(sp, sprite))   {
                if (sprite instanceof Projectile)   {
                    if (!(sp.getColor().equals(sprite.getColor())))   {
                        tr.add(sprite);
                    }
                }
                
            }
        }
    }

    public void Update(long elapsedTime) {
        if (elapsedTime > 0) { // update frame rate
            fps = (int) (1000L / elapsedTime);
        }
        
        LinkedList<Sprite> toRemove = new LinkedList<Sprite>();
        
        //update player
        PlayerSprite player = (PlayerSprite)map.getPlayer();
        checkInput(player, elapsedTime);
        updateSprite((Sprite)player, elapsedTime, toRemove);
        player.update(elapsedTime);
        
        
        Iterator i = map.getSprites();
        while (i.hasNext()) {
            Sprite s = (Sprite)i.next();
            updateSprite(s, elapsedTime, toRemove);
            s.update(elapsedTime);
        }
        
        i = toRemove.iterator();
        while (i.hasNext())  { 
            Sprite sprite = (Sprite)i.next();
            i.remove();
            map.removeSprite(sprite);
        }
    }
    

    public void draw(Graphics g) {
        Graphics2D g2 = (Graphics2D) g;
        g2.setRenderingHint(
            RenderingHints.KEY_TEXT_ANTIALIASING,
            RenderingHints.VALUE_TEXT_ANTIALIAS_ON);

        render.draw(g2, map, RunnerApp.WIDTH, RunnerApp.HEIGHT);
    }
    
    
    private class KeyHandler extends KeyAdapter {
        public void keyPressed(KeyEvent e)	{
			int keyCode = e.getKeyCode();
			if (keyCode == KeyEvent.VK_UP)   {
                keys.setUp(true);
            }
            if (keyCode == KeyEvent.VK_DOWN)   {
                keys.setDown(true);
            }
            if (keyCode == KeyEvent.VK_RIGHT)   {
                keys.setRight(true);
            }
            if (keyCode == KeyEvent.VK_LEFT)   {
                keys.setLeft(true);
            }
            if (keyCode == KeyEvent.VK_A)   {
                keys.setA(true);
            }
            if (keyCode == KeyEvent.VK_D)   {
                keys.setD(true);
            }
            if (keyCode == KeyEvent.VK_W)   {
                keys.setW(true);
            }
            if (keyCode == KeyEvent.VK_S)   {
                keys.setS(true);
            }
            if (keyCode == KeyEvent.VK_SPACE)   {
                keys.setSpace(true);
            }
		}
		public void keyReleased(KeyEvent e)	{
			int keyCode = e.getKeyCode();
			if (keyCode == KeyEvent.VK_UP)   {
                keys.setUp(false);
            }
            if (keyCode == KeyEvent.VK_DOWN)   {
                keys.setDown(false);
            }
            if (keyCode == KeyEvent.VK_RIGHT)   {
                keys.setRight(false);
            }
            if (keyCode == KeyEvent.VK_LEFT)   {
                keys.setLeft(false);
            }
            if (keyCode == KeyEvent.VK_A)   {
                keys.setA(false);
            }
            if (keyCode == KeyEvent.VK_D)   {
                keys.setD(false);
            }
            if (keyCode == KeyEvent.VK_W)   {
                keys.setW(false);
            }
            if (keyCode == KeyEvent.VK_S)   {
                keys.setS(false);
            }
            if (keyCode == KeyEvent.VK_SPACE)   {
                keys.setSpace(false);
            }
		}
    }
}