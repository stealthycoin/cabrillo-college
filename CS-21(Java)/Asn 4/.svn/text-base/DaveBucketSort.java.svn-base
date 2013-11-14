/*	David Herring
 *	david.a.herring@gmail.com
 *	dherring
 *	Assignment 4 (Radix/Bucket Sort)
 *	March 23, 2011
 *	BucketSort.java
 *	accepts a series of input and places them into buckets to sort them
 *	working/tested
 *
 *	Additional Comments: run with -math as argument to use a slightly slower mathmatical calculation
 *		to find the digit
 */

import java.util.*;

public class DaveBucketSort {

	private static int d = 9;	//number of digits
	private static int k = 10;	//range of digits
	//Creates new buckets and disperses ints
	private ArrayList<Integer> al = new ArrayList<Integer>();
	private ArrayList<ArrayList<Integer>> B = new ArrayList<ArrayList<Integer>>();

	
	public static void main(String args[]){
		DaveBucketSort bs = new DaveBucketSort();
		if(args.length == 1 && args[0] == "-math")
			bs.radixSort(true);
		else
			bs.radixSort();
		bs.print();
	}
	
	public DaveBucketSort() {
		for(int i=0; i<k; i++)
			B.add(new ArrayList<Integer>());
		Scanner scn = new Scanner(System.in);
		System.out.println("Gonna cast a spell");
		while(scn.hasNext())
			al.add(scn.nextInt());
		System.out.println("Input read");
	}
	
	//Creates buckets for the nth number
	private void bucketSort(int n, boolean b) {
		
		int size = al.size();
		
		while(al.size() > 0)
			B.get(getDigit(al.get(0), n, b)).add(al.remove(0));
		
		//Places ints back into arraylist
		//note that using the remove method of relocating values means that the ArrayList
		//does not need to be emptied
		for(int i=0; i<k; i++)
			for(int k=0; k<B.get(i).size(); k++)
				al.add(B.get(i).get(k));
	}
	
	//passes the ArrayList and the nth number
	private void radixSort(boolean b) {
		for(int i=0; i<d ; i++)
			bucketSort(i, b);
	}
	
	//defaults too computer science calculation
	private void radixSort(){
		radixSort(false);
	}
	
	private int getDigit(int i, int n, boolean b) {
		//Math Style
		if(b)
			return (i / (int)Math.pow(10, n)) % 10;
		
		//CS Style
		while(n > 0){
			i = i / 10;
			n--;
		}
		return i%10;
	}
	
	private void print() {
		for(int i=0; i<al.size(); i++)
			System.out.format("%09d%n", al.get(i));
	}
}

