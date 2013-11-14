    import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.Iterator;

public class ImageSequence {
	private ArrayList<ImageFrame> frames;
	private int currFrame = 0;
	private long cycleTime;
	private long totalDuration;
	
	public ImageSequence()	{
		frames = new ArrayList<ImageFrame>();
	}
	
	public void addFrame(BufferedImage image, long duration)	{
		totalDuration += duration;
		frames.add(new ImageFrame(image, totalDuration));
	}
	
	public Iterator frames()	{
		return frames.iterator();
	}
	
	public void getFramesFrom(ImageSequence seq)	{
		Iterator i = seq.frames();
		while (i.hasNext())	{
			ImageFrame frame = (ImageFrame)i.next();
			addFrame(frame.image, frame.duration-totalDuration);
		}
	}
	
	public BufferedImage getImage()	{
		if (frames.size() == 0)	{
			return null;
		}
		else	{
			return (frames.get(currFrame).image);
		}
	}
	
	public void update(long elapsedTime)	{
		if (frames.size() > 1)	{
			cycleTime += elapsedTime;
			if (cycleTime >= totalDuration)	{
				cycleTime = cycleTime % totalDuration;
				currFrame = 0;
			}
			while (cycleTime > (frames.get(currFrame)).duration)	{
				currFrame++;
			}
		}
	}
	
	public void reset()	{
		cycleTime = 0;
		currFrame = 0;
	}
	
	private class ImageFrame	{
		BufferedImage image;
		long duration;
		public ImageFrame(BufferedImage image, long duration)	{
			this.image = image;
			this.duration = duration;
		}
	}
}
