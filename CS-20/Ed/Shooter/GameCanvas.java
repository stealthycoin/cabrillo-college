import java.awt.*;
import java.awt.image.BufferStrategy;

public class GameCanvas extends Canvas implements Runnable	{
	public static final int NUM_BUFFERS = 2;
	public static final int DEFAULT_PERIOD = 10;
	public static final int MAX_DELAYS = 16;
	
	private volatile int period;
	private volatile boolean running;
	private volatile boolean paused;
	private Thread animator;
	private BufferStrategy strategy;
	
	public GameCanvas()	{
		int refreshRate = GraphicsEnvironment
			.getLocalGraphicsEnvironment()
			.getDefaultScreenDevice()
			.getDisplayMode()
			.getRefreshRate();
		if (refreshRate == DisplayMode.REFRESH_RATE_UNKNOWN)	{
			period = DEFAULT_PERIOD;
		}
		else	{
			setFramePeriod(1000 / refreshRate);
		}
	}
	
	
	public void setFramePeriod(int newPeriod)	{
		if (newPeriod >= 0)	{
			period = newPeriod;
		}
	}
	
	public int getFramePeriod()	{
		return period;
	}
	
	public boolean isRunning()	{
		return running == true;
	}
	
	public void startGame()	{
		if (animator == null || !running)	{
			animator = new Thread(this);
			animator.start();
		}
	}
	
	public void stopGame()	{
		running = false;
	}
	
	public boolean isPaused()	{
		return paused == true;
	}
	
	public void setPaused(boolean pauseState)	{
		paused = pauseState;
	}
	
	public void run()	{
		try	{
			loopInit();
			gameLoop();
		} catch (Exception e)	{
			e.printStackTrace();
		} finally	{
			exitGame();
		}
	}
	
	public void loopInit()	{
		requestFocusInWindow();
		if (strategy == null)	{
			createBufferStrategy(NUM_BUFFERS);
			strategy = getBufferStrategy();
		}
		running = true;
	}
	
	public void gameLoop()	{
		long startTime = System.nanoTime();
		long currTime = startTime;
		long sleepTime = period;
		int numDelays = 0;
		while (running)	{
			long elapsedTime = System.nanoTime() - currTime;
			currTime += elapsedTime;
			Update(elapsedTime / 1000000L);
			render();
			long timeDiff = System.nanoTime() - currTime;
			sleepTime = period - timeDiff / 1000000L;
			if (sleepTime > 0)	{
				try	{
					Thread.sleep(sleepTime);
					numDelays = 0;
				} catch (InterruptedException ie)	{
					ie.printStackTrace();
					running = false;
				}
			}
			else if (++numDelays > MAX_DELAYS)	{
				Thread.yield();
				numDelays = 0;
			}
		}
	}
	
	
	private void render()	{
		Graphics g = null;
		try	{
			g = strategy.getDrawGraphics();
			draw(g);
		} catch (Exception e)	{
			e.printStackTrace();
		} finally	{
			g.dispose();
		}
		if (!strategy.contentsLost())	{
			strategy.show();
			Toolkit.getDefaultToolkit().sync();
		}	
		else	{
			System.out.println("contents lost");
		}
	}
	
	public void exitGame()	{
		try	{
			System.exit(0);
		} catch	(java.security.AccessControlException e)	{}
	}

	public void Update(long elapsedTime)	{
	}
	
	public void draw(Graphics g)	{
	}
}