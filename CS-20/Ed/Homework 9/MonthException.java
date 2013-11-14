/**
    Exception subclass.
*/
public class MonthException extends Exception   {
    
    /**
        Creates the exception using a default message.
    */
    public MonthException() {
        super("Invalid month");
    }
    
    /**
        Creates the exception using a custom message.
        
        @param message Reason for exception
    */
    public MonthException(String message) {
        super(message);
    }
    
}
