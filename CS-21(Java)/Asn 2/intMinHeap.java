import java.io.Serializable;

public class intMinHeap implements Serializable {
    private static final long serialVersionUID = -6024904606063528526L;
    private int [] A;
    private int capacity; // size of array A
    private int size; // size of data in array A
    private boolean heap;
    
    
    public static void main(String[] args) {
        intMinHeap imh = new intMinHeap();
        System.out.println("John William Carlyle");
        imh.buildheap();
        imh.print();
        System.out.println(imh.extractmin());
        System.out.println(imh.extractmin());
        imh.print();
        imh.heapinsert(1);
        imh.print();
        imh.heapsort();
        imh.print();
    }
    
    
    public intMinHeap() {
        //treating it as 1 based
        A = new int[]{0, 5, 3, 7, 1, 2, 4, 9, 8, 6, 10, -1, 0,0,0,0};
        size = 11;
        capacity = A.length - 1;
        heap = false;
    }
    
    public void heapify(int i) {
        int n = indexOfSmallest(left(i), right(i), i);
        if (n != i) {
            swap(i, n);
            heapify(n);
        }
        heap = true;
    }
    
    public void buildheap() {
        for (int i = size / 2 ; i > 0 ; i--) {
            heapify(i);
        }
    }
    
    public void heapsort() {
        int oldsize = size;
        for (int i = size ; i > 1 ; i--) {
            swap(i, 1);
            size--;
            heapify(1);
        }
        size = oldsize;
        reverse();
        heap = false;
    }
    
    public int minimum() {
        if (heap) return A[1];
        return -1;
    }

    public int extractmin() {
        int min = A[1];
        A[1] = A[size];
        size--;
        heapify(1);
        return min;
    }
    
    public void decreaseKey(int i, int k) {
        if (k > A[i]) return;
        A[i] = k;
        while (i > 1 && A[parent(i)] > A[i]) {
            swap(i, parent(i));
            i = parent(i);
        }
    }
    
    public void heapinsert(int n) {
        size++;
        A[size] = n + 1;
        decreaseKey(size, n);
    }
    
    public void print() {
        System.out.println(toString());
    }
    
    public String toString() {
        String ret = "";
        for (int i = 1; i <= size ; i++) {
            int v = A[i];
            ret += "|" + v;
        }
        return ret + "|";
    }
    
    public void swap(int a, int b) {
        int temp = A[a];
        A[a] = A[b];
        A[b] = temp;
    }
    
    public int indexOfSmallest(int a, int b, int c) {
        /*
         * Yes, I just re-learned how to use the ?: operator and am using lots of them
         * */
        int va = (a > 0 ? A[a] : Integer.MAX_VALUE);
        int vb = (b > 0 ? A[b] : Integer.MAX_VALUE);
        int vc = (c > 0 ? A[c] : Integer.MAX_VALUE);
        return (va < vb ? (va < vc ? a : c) : (vb < vc ? b : c));
    }
    
    public void reverse() {
       int left  = 1;
       int right = size;
       while (left < right) {
           swap(left, right);
           left++;
           right--;
        }
    }
    
    public int left(int i) {
        return (2*i <= size ? 2*i : -1);
    }
    
    public int right(int i) {
        return (2*i+1 <= size ? 2*i+1 : -1);
    }
    
    public int parent(int i) {
        return i/2;
    }
}