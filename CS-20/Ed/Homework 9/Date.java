import java.util.*;

/**
    Represents a date in time.
*/
public class Date {
    private static final int START_DAY = 1;
    private static final int START_MONTH = 1;
    private static final int START_YEAR = 2001;
    private static final int MONTHS_IN_YEAR = 12;
    
    private int month, day, year;
    private GregorianCalendar cal;
    
    /**
        Unused Extra credit method
    */
    public static boolean isValid(Date date)    {
        int day = date.getDay();
        int month = date.getMonth();
        int year = date.getYear();
        GregorianCalendar cal = new GregorianCalendar(year, month, day);
        if (month < 1 || month > 12)   {
            return false;
        }
        if (day < 1 || day > cal.getActualMaximum(GregorianCalendar.DAY_OF_MONTH))   {
            return false;
        }
        
        return true;
    }
    
    /**
        Constructs a new date at 1/1/2001
    */
    public Date()   {
        month = START_MONTH;
        day = START_DAY;
        year = START_YEAR;
    }
    
    /**
        Constructs a date with the string date
        
        @throws DayException invalid day
        @throws MonthException invald month
        @param date The string to be parsed into a date.
    */
    public Date(String date)  throws DayException, MonthException  {
        int firstSlash = date.indexOf("/");
        int secondSlash = date.indexOf("/", firstSlash + 1);
        
        if (secondSlash == -1 || firstSlash == -1)   {
            throw new DayException("Invalid format, un-parsable");
        }
            
        String month = date.substring(0, firstSlash);
        String day = date.substring(firstSlash + 1, secondSlash);
        String year = date.substring(secondSlash + 1, date.length());
        
        month =  month.trim();
        day = day.trim();
        year = year.trim();
        
        int m, d, y;
        
        try {
            m = Integer.parseInt(month);
            d = Integer.parseInt(day);
            y = Integer.parseInt(year);
        }   catch (NumberFormatException ne)  {
            throw new DayException("Invalid format, un-parsable");
        }
        
        setDate(y, m, d);
    }
    
    
    /**
        Date constructor that constructs the object from three numbers
        
        @throws MonthException Invalid month
        @throws DayException Invalid day
        @param year Year
        @param month Month
        @param day Day
    */
    public Date(int year, int month, int day)   throws  MonthException,
                                                        DayException {
        setDate(year, month, day);
    }
    
    /**
        Set Date acutally sets the fields of the Date object
        
        @throws MonthException Invalid month
        @throws DayException Invalid day
        @param newYear Year
        @param newMonth Month
        @param newDay Day

    */
    public void setDate(int newYear, int newMonth, int newDay)  
                                    throws MonthException, DayException {
        year = newYear;
        month = newMonth;
        day = newDay;
        
        cal = new GregorianCalendar(year, month - 1, day);
        int daysInMonth = cal.getActualMaximum(GregorianCalendar.DAY_OF_MONTH);
        
        
        if (newMonth > MONTHS_IN_YEAR || newMonth < 1)   {
            throw new MonthException();
        }
        if (day > daysInMonth || day < 1)   {
            throw new DayException();
        }
       
    }
    
    /**
        returns the date's year
        
        @return integer representation of the year
    */
    public int getYear()    {
        return year;
    }
    
    /**
        returns the date's month
        
        @return integer representation of the month
    */
    public int getMonth()   {
        return month;
    }
    
    /**
        returns the date's day
        
        @return integer representation of the day
    */
    public int getDay()     {
        return day;
    }
    
    /**
        Adds a day to the fields, will rollover months and years,
            calculates in leapyear
        @throws MonthException invalid month
        @throws DayException invalid day
        @return self which happens to be the new date
    */
    public Date nextDay() throws MonthException, DayException    {
        cal = new GregorianCalendar(year, month -  1, day);
        int daysInMonth = cal.getActualMaximum(GregorianCalendar.DAY_OF_MONTH);
        day += 1;
        
        
        if (day > daysInMonth)  {
            day = 1;
            month++;
        }
        if (month > MONTHS_IN_YEAR)   {
            month = 1;
            year++;
        }
        setDate(year, month, day);
        
        return this;
    }
    
    /**
        Returns a string representation of the date
            In the form of MM/DD/YYYY
            
        @return A string in the format of MM/DD/YYYY
    */
    public String toString()    {
        return month + "/" + day + "/" + year;
    }
    
}
