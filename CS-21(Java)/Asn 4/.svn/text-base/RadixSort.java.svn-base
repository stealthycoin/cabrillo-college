/**
 *  Name: John Carlyle
 *  Email: john.w.carlyle@gmail.com
 *  Pengo: jcarlyle
 *  Asn#4: Radix / Bucket Sort
 *  Date of mod: 3/27/10
 *  Description: Sorts using a combination of radix sort and either bucket or
 *  counting sort. Defaults to bucket sort, use the flag -cs to use counting
 *  sort as the stable sort helper to radixs sort.
 *
 *  Code Status: Working/Tested
 *  Compile Status: No warnings or errors
 *
 *  Comments: Did the extra credit assignment of adding counting sort as an
 *  option. Use the argument -cs to use counting sort instead of bucket sort.
 **/



import java.io.*;
import java.util.ArrayList;
import java.text.DecimalFormat;
import java.util.Arrays;

public class RadixSort {
    //Number of buckets to create, 0-9 (10) digits so ten buckets are needed
    private final int NUM_BUCKETS = 10;
    //Line lengths are all 9 digits long
    private final int LINE_LENGTH = 9;
    //make sure to print out the same format as was read in
    private final DecimalFormat df = new DecimalFormat("000000000");
    
    //arrays needed for both sorting routines
    private ArrayList<Integer> list;
    private ArrayList<ArrayList<Integer>> buckets;
    private ArrayList<Integer> b;
    
    /**
     * Starting point of the program.
     *
     **/
    public static void main(String[] args) {
        RadixSort rs = new RadixSort();
		rs.radixBucketSort();
    }
 
    /**
     *
     *  Initiate object by reading input file.
     *
     **/
    public RadixSort() {
        list = readStream(System.in);
    }
 
 
 
    /**
     *
     * Prints the given list with the correct format
     *
     **/
    public void printList(ArrayList<Integer> l) {
		StringBuilder sb = new StringBuilder();
        for (Integer i : l) {
			sb.append(df.format(i));
			sb.append("\n");
        }
		System.out.print(sb.toString());
    }
 
    /**
     *
     *  Empty the buckets for reuse.
     *
     **/
    public void clearBuckets() {
        for (int j = 0 ; j < NUM_BUCKETS ; j++) {
            buckets.get(j).clear();    
        }
    }
 
 
    /**
     *
     *  Simple radix sort.
     *
     *
     **/
    public void radixBucketSort() {
        buckets = new ArrayList<ArrayList<Integer>>();
        for (int i = 0 ; i < NUM_BUCKETS; i++) {
            buckets.add(new ArrayList<Integer>());
        }
        
        for (int i = 1 ; i <= LINE_LENGTH ; i++) {
            bucketSort(i);
        }
        
        printList(list);
    }
    
    /**
     *  Bucket sort.
     *  @param i Is the digit to bucket sort with.
     **/
    public void bucketSort(int i) {
		int num;
        for (int j = 0 ; j < list.size() ; j++) {
            num = list.get(j);
            buckets.get(getDigit(num, i)).add(num);
        }
        list.clear();
        for (ArrayList<Integer> l : buckets) {
            for (Integer integer : l) {
                list.add(integer);
            }
        }
        
            clearBuckets();
    }
 
    /**
     *  
     *  getDigit returns the nth digit in some number num
     *
     *  @param num Number to get a digit from
     *  @param n The digit to get from number
     *  
     **/
    public int getDigit(int num, int n) {
        return (num / lookup(n)) % 10;
    }
    
     /*  Counting sort by digit k of the list items
     *
     **/
        
    
	
	//default:
	//return (int)Math.pow(10, power-1);
	public int lookup(int power) {
		switch (power) {
			case 1:
				return 1;
			case 2:
				return 10;
			case 3:
				return 100;
			case 4:
				return 1000;
			case 5:
				return 10000;
			case 6:
				return 100000;
			case 7:
				return 1000000;
			case 8:
				return 10000000;
			case 9:
				return 100000000;
			case 10:
				return 1000000000;
		}
		return 1;
	}
	
    public void printList(int[] list) {
		StringBuilder sb = new StringBuilder();
        for (int i : list) {
            sb.append(i);
			sb.append("\n");
        }
		System.out.print(sb.toString());
    }
    
    /**
     *
     *  readStream returns an arrayList of integers from an input stream
     *
     **/
    public ArrayList<Integer> readStream(InputStream is) {
        
        ArrayList<Integer> nums = new ArrayList<Integer>();
        
        try {
            
            BufferedReader br = new BufferedReader(new InputStreamReader(is));
            String line;
            while ((line = br.readLine()) != null) {
                nums.add(Integer.valueOf(line));
            }
            
            br.close();
            
            return nums;
            
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        
        return null;
    }
    
}   