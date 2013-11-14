import java.util.Random;

public class InsertionSort {
    
    public static void main(String[] args) {
        Random rand = new Random();
        
        int n = 1000000;
        
        int[] a = new int[n];
        for (int i = 0 ; i < a.length ; i++) {
            a[i] = rand.nextInt(n-1) + 1;
        }
        
        long start = System.nanoTime();
        insertionSort(a);
        long estimatedTime = System.nanoTime() - start;
        System.out.println(estimatedTime);
    }
    
    public static void printArray(int[] a) {
        for (int i : a) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
    
    public static int[] insertionSort(int[] a) {
        int[] b = new int[a.length];
        
        for (int i = 0 ; i < a.length ; i++) {
            int element = a[i];
            boolean inserted = false;
            for (int j = 0 ; j < b.length && !inserted ; j++) {
                if (b[j] == 0 || b[j] > element) {
                    insert(b, element, j);
                    inserted = true;
                }
            }
        }
        
        return b;
    }
    
    public static void insert(int[]a, int e, int i) {
        if (i >= 0 && i < a.length) {
            for (int j = a.length - 1 ; j > i ; j--) {
                a[j] = a[j-1];
            }
            a[i] = e;
        }
    }
}
