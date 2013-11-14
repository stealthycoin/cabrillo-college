import java.util.*;

/**
    Dynamic data structure LinkedList
*/
public class LinkedList {
    private Node head;
    
    /**
      Constructs empty LinkedList  
    */
    public LinkedList() {
        head = null;
    }

    /**
        Clears out the LinkedList
    */
    public void clear() {
        head = null;
    }
    
    
    /**
        Finds the index of specified item
        
        @param item Item to find index of
        @return Index of item.
    */
    public int indexOf(Object item) {
        Node position = head;
        int count = 0;
        while (position != null) {
            if (item.equals(position.data)) {
                return count;
            }
            count++;
            position = position.link;
        }
        throw new NoSuchElementException();
    }

    /**
        Traverses the list and finds item number index and returns it;
        @param index index ot get object from
        
        @return Object from linked list
    */
    public Object get(int index) {
        Node position = head;
        int count = 0;
        while (position != null && count < index) {
            count++;
            position = position.link;
        }
        if (count != index) {
            throw new NoSuchElementException();
        }
        return position.data;
    }
    
    /**
        Prints the list to standard output
    */
    public void showList() {
        Node position = head;
        while (position != null) {
            System.out.println(position.data);
            position = position.link;
        }
    }
    
    /**
        Adds an object to the end of the list
        
        @param newData object to be added
    */
    public void addToEnd(Object newData)  {
        Node newNode = new Node(newData, null);
        Node position = head;
        while (position != null)    {
            position = position.link;
        }
        position.link = newNode;
    }
    
    /**
        Adds an object ot the beginning of the list
        
        @param newData object to be added
    */
    public void addToStart(Object newData) {
        head = new Node(newData, head);
    }

    /**
        Removes first item in list
    */
    public void removeFromStart() {
        if (head == null) {
            throw new IllegalStateException();
        } else {
            head = head.link;
        }
    }
    
    /**
        Node a nodes to link to eachother.
    */
    private class Node {
        private Object data;
        private Node link;
        
        /**
            Creates a node with datat and a link to another node
            
            @param newData data for node
            @param newLink next node on list
        */
        public Node(Object newData, Node newLink) {
            data = newData;
            link = newLink;
        }
        
        /**
            Returns node's content
            
            @return Returns whatever datat the node is holding
        */
        public Object getData() {
            return data;
        }
    }
    
    /**
        List Iterator easy way to loop thorugh the list
    */
    public class ListIter implements Iterator {
        private Node position;
        private Node previous;
        
        /**
            Starts the iterator at the head
        */
        ListIter() {
            position = head;
            previous = null;
        }
        
        /**
          Checks to see if the list has another object  
          
          @return yes if there is another objet no if there isn't
        */
        public boolean hasNext() {
            return position != null;
        }
        
        /**
            Returns the next object in the list
            
            @return next node in list
        */
        public Object next() {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }
            Object value = position.data;
            previous = position;
            position = position.link;
            return value;
        }
        
        /**
            removes the current node in list
        */
        public void remove() {
            if (position == null) { // no nodes
                throw new IllegalStateException();
            } else if (previous == null) { // at head
                head = head.link;
                position = head;
            } else { // usual case
                previous.link = position.link;
                position = position.link;
            }
        }
        
        /**
            Add something to the list via the iterator
            
            @param newData data to add
        */
        public void add(Object newData) {
            if (position == null && previous != null) {
                // at end of list
                previous.link = new Node(newData, null);
            } else if (position == null || previous == null) {
                // list is empty or position is at head node
                addToStart(newData);
            } else {
                // usual case: previous and position are
                // consecutive nodes
                Node temp = new Node(newData, position);
                previous.link = temp;
                previous = temp;
            }
        }
    }
    /**
        Return a list iterator for this object
        
        @return returns a list iterator object
    */
    ListIter iterator() {
        return new ListIter();
    }
}
