import java.util.Scanner;
/*                                                                                                                                                                                                        
  Runnable class that implements the Stack class.                                                                                                                                                         
*/
public class RunMe {
    /*                                                                                                                                                                                                    
      Main method, reads input doubles                                                                                                                                                                    
      and prints them back in reverse order                                                                                                                                                               
    */
    public static void main(String[] args) {
        Stack stack = new Stack();
        Scanner scanner = new Scanner(System.in);
        //push values onto stack until EOF                                                                                                                                                                
        while (scanner.hasNextDouble()) {
            stack.push(scanner.nextDouble());
        }
        //pop values back from stack and print them                                                                                                                                                       
        Double nextVal;
        while ((nextVal = stack.pop()) != null) {
            System.out.println(nextVal);
        }
    }
}

