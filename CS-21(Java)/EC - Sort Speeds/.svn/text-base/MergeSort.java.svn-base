import java.util.Random;


public class MergeSort {
    
    public static void main(String[] args) {
        
        int n = 1000000;
        Random rand = new Random();
        
        
        int[] a = new int[n];
        for (int i = 0 ; i < n ; i++) {
            a[i] = rand.nextInt(n) + 1;
        }
        
        long start = System.nanoTime();
        mergeSort(a);
        long time = System.nanoTime() - start;
        System.out.println(time);
        
    }
    
    
    /**
     * Mergesort algorithm.
     * @param a an array of Comparable items.
     */
    public static void mergeSort( int [ ] a ) {
        int [ ] tmpArray = new int[ a.length ];
        mergeSort( a, tmpArray, 0, a.length - 1 );
    }
    
    public static void printArray(int[] a) {
        for (int i : a) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
 
    /**
     * Internal method that makes recursive calls.
     * @param a an array of Comparable items.
     * @param tmpArray an array to place the merged result.
     * @param left the left-most index of the subarray.
     * @param right the right-most index of the subarray.
     */
    private static void mergeSort( int [ ] a, int [ ] tmpArray,
            int left, int right ) {
        if( left < right ) {
            int center = ( left + right ) / 2;
            mergeSort( a, tmpArray, left, center );
            mergeSort( a, tmpArray, center + 1, right );
            merge( a, tmpArray, left, center + 1, right );
        }
    }
    
    /**
     * Internal method that merges two sorted halves of a subarray.
     * @param a an array of Comparable items.
     * @param tmpArray an array to place the merged result.
     * @param leftPos the left-most index of the subarray.
     * @param rightPos the index of the start of the second half.
     * @param rightEnd the right-most index of the subarray.
     */
    private static void merge( int [ ] a, int [ ] tmpArray,
            int leftPos, int rightPos, int rightEnd ) {
        int leftEnd = rightPos - 1;
        int tmpPos = leftPos;
        int numElements = rightEnd - leftPos + 1;
        
        // Main loop
        while( leftPos <= leftEnd && rightPos <= rightEnd )
            if( a[ leftPos ] <= a[ rightPos ] )
                tmpArray[ tmpPos++ ] = a[ leftPos++ ];
            else
                tmpArray[ tmpPos++ ] = a[ rightPos++ ];
        
        while( leftPos <= leftEnd )    // Copy rest of first half
            tmpArray[ tmpPos++ ] = a[ leftPos++ ];
        
        while( rightPos <= rightEnd )  // Copy rest of right half
            tmpArray[ tmpPos++ ] = a[ rightPos++ ];
        
        // Copy tmpArray back
        for( int i = 0; i < numElements; i++, rightEnd-- )
            a[ rightEnd ] = tmpArray[ rightEnd ];
    }
    
}