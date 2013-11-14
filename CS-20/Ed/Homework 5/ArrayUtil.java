public class ArrayUtil {
    public final static int LOW = 0;
    public final static int HIGH = 1000;
    private static int comparisons = 0;

    /**
     * The main method begins execution of Java application.
     *
     * @param args not used
     */
    public static void main(String[] args) {
        int[] array = makeArray(10);
        runTests(array);
        insertionSort(array);
        System.out.println("Insertion sort comparisons needed: " + comparisons);
        
        System.out.println("\nMaximum value of array is: " + maxOfArray(array));
        System.out.println("Minimum value of array is: " + minOfArray(array));
        System.out.println("Average value of array is: " + averageOfArray(array));
    }

    /**
     * Accessor method for comparisons.
     *
     * @return Current count of comparisons.
     */
    public static int getComparisons() {
        return comparisons;
    }

    /**
     * Runs tests on the int array.
     *
     * @param array The array to test.
     */
    public static void runTests(int[] array) {
        System.out.println("Original array elements are:");
        showArray(array);
        int[] arrayCopy = copyArray(array);
        bubbleSort(arrayCopy);
        System.out.println("\nBubble Sort comparisons needed: "
            + comparisons);
        System.out.println("Sorted array elements are:");
        showArray(arrayCopy);
        arrayCopy = copyArray(array);
        bubbleSortPlus(arrayCopy);
        System.out.println("Enhanced Bubble Sort comparisons needed: "
            + comparisons);
        showArray(arrayCopy, 0);
        int item = (int) (Math.random() * (array.length - 1));
        System.out.println("\nSearching for: " + array[item]);
        linearSearch(arrayCopy, array[item]);
        System.out.println("Linear search Comparisons needed: "
            + comparisons);
        binarySearch(arrayCopy, array[item]);
        System.out.println("Binary search Comparisons needed: "
            + comparisons);
    }
    
    public static int maxOfArray(int[] array) {
        int max = array[0];
        for (int i = 0 ; i < array.length ; i++)  {
            max = Math.max(max, array[i]);
        }
        return max;
    }
    
    public static int minOfArray(int[] array) {
        int min = array[0];
        for (int i = 0 ; i < array.length ; i++)  {
            min = Math.min(min, array[i]);
        }
        return min;
    }
    
    public static int averageOfArray(int[] array) {
        int total = 0;
        int average;
        int i;
        for (i = 0 ; i < array.length ; i++)  {
            total += array[i];
        }
        average = total / i; 
        return average;
    }
    
    
    public static int[] makeArray(int size) {
        int array[] = new int[size];
        for (int i = 0 ; i < size ; i++)  {
            double num = Math.random();
            num *= 100;
            array[i] = (int)num;
        }
        return array;
    }

    public static int[] copyArray(int[] array) {
        int newArray[] = new int[array.length];
        for (int x = 0 ; x < array.length ; x++)  {
            newArray[x] = array[x];
        }
        return newArray;
    }

    public static void bubbleSort(int[] array) {
        comparisons = 0;
        for (int j = 0 ; j < array.length ; j++)   {
            for (int i = 0 ; i < array.length - 1 ; i++)  {
                if (array[i] > array[i+1])   {
                    swap(i, i+1, array);
                }
                comparisons++;
            }
        }
    }

    public static void bubbleSortPlus(int[] array) {
        comparisons = 0;
         for (int j = 1 ; j < array.length ; j++)  {
            for (int i = 0 ; i < array.length - j ; i++)  {
                if (array[i] > array[i+1])   {
                    swap(i, i+1, array);
                }
                comparisons++;
            }
        }
    }
    
    public static void insertionSort(int[] array)   {
        comparisons = 0;
        for (int i = 0 ; i < array.length ; i++)  {
            for (int j = i ; j > 0 ; j--)  {
                if (array[j] < array[j-1])   {
                    swap(j, j - 1, array);
                }
                comparisons++;
            }
        }
    
    }

    public static int linearSearch(int[] array, int key) {
        comparisons = 0;
        for (int i = 0 ; i < array.length ; i++)  {
            comparisons++;
            if (array[i] == key)    {
                return i; 
            }
        }
        return -1;
    }

    public static int binarySearch(int[] array, int key) {
        comparisons = 0;
        int lowIndex = 0;
        int highIndex = array.length - 1;
        int middleIndex;
        
        while (lowIndex <= highIndex)    {
            comparisons++;
            middleIndex = (lowIndex + highIndex) / 2;
            if (array[middleIndex] == key)   {
                return middleIndex;
            }
            else if (array[middleIndex] < key)  {
                lowIndex = middleIndex + 1;
            }
            else    {
                highIndex = middleIndex - 1;
            }
        }
        
        return -1;
    }

    public static void showArray(int[] array) {
        for (int x = 0 ; x < array.length ; x++)   {
            System.out.print(array[x] + " ");
        }
        System.out.println("");
    }

    public static void showArray(int[] array, int start) {
        for (int x = start ; x < array.length ; x++)  {
            System.out.print(array[x] + " ");
        }
    }
    
    public static void swap(int iOne, int iTwo, int[] array)  {
        int temp = array[iOne];
        array[iOne] = array[iTwo];
        array[iTwo] = temp;
    }
}
