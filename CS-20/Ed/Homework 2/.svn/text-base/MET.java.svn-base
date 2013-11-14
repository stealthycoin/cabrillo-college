

public class MET {
	
	final int RUNNING_MET = 10;
	final int BASKETBALL_MET = 8;
	final int SLEEPING_MET = 1;
	
	/**
		Converts pounds to kilograms
		
		@author John Carlyle
	*/
	public double poundToKg(double value)	{
		double newValue = value/ 2.2;
		
		
		return newValue;
	}
	
	/**
		Main Method, calculates calories burned a minute and displays them
		
		@author John Carlyle
	*/
	public static void main(String[] args)	{
		 MET met = new MET();
		double runningTotal = 0.0175 * met.RUNNING_MET * met.poundToKg(150D);
		runningTotal *= 30;
		
		
		double basketballTotal = 0.0175 * met.BASKETBALL_MET * met.poundToKg(150D);
		basketballTotal *= 30;
		
		
		double sleepingTotal = 0.0175 * met.SLEEPING_MET * met.poundToKg(150D);
		sleepingTotal *= 360;
		
		
		double total = runningTotal + basketballTotal + sleepingTotal;
		
		System.out.println("Calories burned: " + total);
		
	}
}
