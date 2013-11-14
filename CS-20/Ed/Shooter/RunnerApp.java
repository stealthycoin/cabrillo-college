import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class RunnerApp extends JFrame	{
	public static final int WIDTH = 800, HEIGHT = 600;
	public static GameManager manager;
	
	public static void main(String[] args)	{
		RunnerApp frame = new RunnerApp();
		manager = new GameManager();
		manager.setPreferredSize(new Dimension(WIDTH, HEIGHT));
		
		frame.add(manager);
		frame.pack();
		
		manager.init();
		frame.setVisible(true);
		manager.startGame();
	}
	
	public RunnerApp()	{
		super("Triangle man");
		addWindowListener(new WinHandler());
	}
	
	private class WinHandler extends WindowAdapter	{
		public void windowClosing(WindowEvent e)	{
			manager.stopGame();
		}
		
		public void windowActivated(WindowEvent e)	{
			manager.setPaused(false);
		}
		
		public void windowDeactivated(WindowEvent e)	{
			manager.setPaused(true);
		}
	}
}
