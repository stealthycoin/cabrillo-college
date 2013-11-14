public class Node {
    public Node next;
    public Double data;

    public Node() {
        data = null;
        next = null;
    }

    public Node(double d) {
        this(new Double(d));
    }

    public Node(Double d) {
        data = d;
        next = null;
    }
}



