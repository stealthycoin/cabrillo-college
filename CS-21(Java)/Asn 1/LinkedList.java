/*                                                                                                                                                                                                        
 John Carlyle                                                                                                                                                                                             
 john.w.carlyle@gmail.com                                                                                                                                                                                 
 jcarlyle                                                                                                                                                                                                 
 Asn#1 (Linked List)                                                                                                                                                                                      
 Last Modification: 2/10/10                                                                                                                                                                               
 LinkedList.java                                                                                                                                                                                          
 Linked List file holds all the data. Extremly basic LinkedList Behavior.                                                                                                                                 
 Code Status: working/tested                                                                                                                                                                              
 No errors or warnings                                                                                                                                                                                    
*/

/*                                                                                                                                                                                                        
  Basic LinkedList class.                                                                                                                                                                                 
  Collection of nodes that link to the next node and store a double.                                                                                                                                      
*/
public class LinkedList {

    protected Node head;

    /*                                                                                                                                                                                                    
      Creates a new LinkedList                                                                                                                                                                            
    */
    public LinkedList() {
        head = new Node();
    }

    /*                                                                                                                                                                                                    
      Converts double to Double and adds to the end of the list.                                                                                                                                          
    */
    public void put(double d) {
        put(new Double(d));
    }

    /*                                                                                                                                                                                                    
      Adds a Double to the end of the list.                                                                                                                                                               
    */
    public void put(Double d) {
        Node n = head;
        while (n.next != null) {
            n = n.next;
        }
        n.next = new Node(d);
    }

    /*                                                                                                                                                                                                    
      Returns the Double at the sepcificed index in the list.                                                                                                                                             
    */
    public Double get(int index) {
        Node n = head.next;
        if (n == null) return null;
        for (int i = 0 ; i < index ; i++) {
            if (n == null) return null;
            else if (n.next != null) n = n.next;
            else return null;
        }
        return n.data;
    }


    /*                                                                                                                                                                                                    
      Removes the Double at the sepcified inex in the list.                                                                                                                                               
    */
    public void remove(int index) {
        Node last = head;
        Node n = head.next;
        for (int i = 0 ; i < index ; i++) {
            if (n == null || n.next == null) return;
            last = n;
            n = n.next;
        }
        if (n == null) last.next = null;
        else last.next = n.next;
    }
}
