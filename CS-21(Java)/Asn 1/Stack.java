/*                                                                                                                                                                                                        
  Subclass of the LinkedList class.                                                                                                                                                                       
  Extends its functionality by adding pop/push methods.                                                                                                                                                   
*/
public class Stack extends LinkedList {

    /*                                                                                                                                                                                                    
      Creates a new Stack.                                                                                                                                                                                
    */
    public Stack() {
        super();
    }

    /*                                                                                                                                                                                                    
      Adds a new double to the beginning of the list.                                                                                                                                                     
    */
    public void push(double d) {
        Node n = new Node(d);
        n.next = head.next;
        head.next = n;
    }

    /*                                                                                                                                                                                                    
      Returns the first Double in the list and removes it.                                                                                                                                                
    */
    public Double pop() {
        Double retval = get(0);
        remove(0);
        return retval;
    }
}
