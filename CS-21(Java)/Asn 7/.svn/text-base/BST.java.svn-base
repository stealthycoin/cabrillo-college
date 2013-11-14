import java.io.*;
import java.util.*;

public class BST {
    
    private Node root;
    
    public BST() {
        root = null;
    }
    
    public boolean isEmpty() {
        if (root == null)
            return true;
        return false;
    }
    
    public void insert(int i) {
        _insert(new Node(i));
    }
    
    private void _insert(Node n) {
        Node p = null;
        Node t = root;
        while (t != null) {
            p = t;
            if (n.key < t.key) 
                t = t.left;
            else 
                t = t.right;
        }
        n.parent = p;
        if (p == null) {
            root = n;
            return;
        }
        if (n.key < p.key)
            p.left = n;
        else
            p.right = n;
    }
    
    public Node search(int i) {
        return _search(root, i);
    }
    
    private Node _search(Node n, int k) {
        if (n == null || k == n.key) return n;
        if (k < n.key) return _search(n.left, k);
        else return _search(n.right, k);
    }
    
    public Node delete(int i) {
        Node n = search(i);
        if (n != null) {
            return _delete(n);
        }
        return null;
    }
    
    private Node _delete(Node n) {
        Node t, x;
        if (n.left == null || n.right == null) {
            t = n;
        }
        else {
            t = _sucessor(n);
        }
        if (t.left != null) {
            x = t.left;
        }
        else {
            x = t.right;
        }
        if (x != null) {
            x.parent = t.parent;
        }
        if (t.parent == null) {
            root = x;
        }
        else if (t == t.parent.left) {
            t.parent.left = x;
        }
        else {
            t.parent.right = x;
        }
        if (t != n) {
            swap(t,n);
        }
        return t;
    }
    
    public int predecessor(int i) {
        Node n = search(i);
        n = _predecessor(n);
        return n.key;
    }
    
    private Node _predecessor(Node n) {
        if (n.left != null)
            return _max(n.left);
        Node t = n.parent;
        while (t != null && n == t.left) {
            n = t;
            t = t.parent;
        }
        return t;
    }
    
    public int sucessor(int i) {
        Node n = search(i);
        n = _sucessor(n);
        return n.key;
    }
    
    private Node _sucessor(Node n) {
        if (n.right != null)
            return _min(n.right);
        Node t = n.parent;
        while (t != null && n == t.right) {
            n = t;
            t = t.parent;
        }
        return t;
    }
    
    public int min() {
        return _min(root).key;
    }
    
    private Node _min(Node n) {
        while (n.left != null)
            n = n.left;
        return n;
    }
    
    public int max() {
        return _max(root).key;
    }
    
    private Node _max(Node n) {
        while (n.right != null)
            n = n.right;
        return n;
    }
    
    public void inorder() {
        _inorder(root);
    }
    
    private void _inorder(Node n) {
        if (n == null) return;
        _inorder(n.left);
        System.out.print(" " + n.key + " ");
        _inorder(n.right);
    }
    
    public void postorder() {
        _postorder(root);
    }
    
    private void _postorder(Node n) {
        if (n == null) return;
        _postorder(n.left);
        _postorder(n.right);
        System.out.print(" " + n.key + " ");
    }
    
    public void preorder() {
        _preorder(root);
    }
    
    private void _preorder(Node n) {
        if (n == null) return;
        System.out.print(" " + n.key + " ");
        _preorder(n.left);
        _preorder(n.right);
    }
    
    private void swap(Node a, Node b) {
        Node t = a;
        a = b;
        b = t;
    }
    
    class Node {
        public Node parent;
        public Node left;
        public Node right;
        public int key;
        
        public Node() {
            this(0);
        }
        
        public Node(int k) {
            key = k;
            parent = left = right = null;
        }
    }
    
    public static void main(String[] args) {
        BST bst = new BST();
        
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            
            String line;
            while ((line = br.readLine()) != null)
                if (!line.trim().startsWith("#")) processCommand(bst, line);
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    private static void processCommand(BST bst, String cmd) {
        String[] args = cmd.split(" ");
        Node n;
        if (args[0].equals("predecessor")) {
            n = bst.search(Integer.valueOf(args[1]));
            if (n == null) {
                System.out.println(args[1] + " not in tree.");
            }
            else {
                n = bst._predecessor(n);
                if (n != null)
                    System.out.println(args[1] + " predecessor is " + n.key + ".");
                else
                    System.out.println("no predecessor for " + args[1] + ".");
            }
        }
        else if (args[0].equals("sucessor")) {
            n = bst.search(Integer.valueOf(args[1]));
            if (n == null) {
                System.out.println(args[1] + " not in tree.");
            }
            else {
                n = bst._predecessor(n);
                if (n != null)
                    System.out.println(args[1] + " sucessor is " + n.key + ".");
                else
                    System.out.println("no sucessor for " + args[1] + ".");
            }
        }
        else if (args[0].equals("insert")) {
            bst.insert(Integer.valueOf(args[1]));
            System.out.println("inserted " + args[1] + ".");
        }
        else if (args[0].equals("delete")) {
            n = bst.delete(Integer.valueOf(args[1]));
            if (n != null)
                System.out.println(n.key + " deleted.");
            else
                System.out.println("delete " + args[1] + " - not found.");
        }
        else if (args[0].equals("min")) {
            if (bst.isEmpty())
                System.out.println("tree empty.");
            else
                System.out.println("min is " + bst.min() + ".");
        }
        else if (args[0].equals("max")) {
            if (bst.isEmpty())
                System.out.println("tree empty.");
            else
                System.out.println("max is " + bst.max() + ".");
        }
        else if (args[0].equals("inorder")) {
            System.out.print("inorder:");
            bst.inorder();
            System.out.println();
        }
        else if (args[0].equals("preorder")) {
            System.out.print("preorder:");
            bst.preorder();
            System.out.println();
        }
        else if (args[0].equals("postorder")) {
            System.out.print("postorder:");
            bst.postorder();
            System.out.println();
        }
    }
}