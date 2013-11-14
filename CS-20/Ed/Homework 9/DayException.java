/**
    Exception subclass.
*/
public class DayException extends Exception   {
    
    /**
        Creates a exception using the default message.
    */
    public DayException() {
        super("Invalid day");
    }
    
    /**
        Creates an exception using a custom message
        
        @param message Reason for exception
    */
    public DayException(String message) {
        super(message);
    }
    
}