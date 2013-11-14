/**
 *
 *	Name: John Carlyle
 *	Email: john.w.carlyle@gmail.com
 *	pengo: jcarlyle
 *	Asn#5: Hash Tables
 *	Date of modification: April, 10 2010
 *	Filename: hasthTable.java
 *	Description:
 *	Code Status: Working/tested
 *	Warnings/Errors: One warning. It is a warning about the fact taht I am
 *	inserting an object into array of LinkedLists without any genearics.
 *	Problem is ifyou add the correct generics it will not compile.
 *	Currenty an issue with java.
 *	Only way to avoid this warning would be to write my own linked list
 *	class.
 **/

import java.util.Scanner;
import java.util.LinkedList;
import java.io.PrintWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.FileInputStream;


/**
 *  Hashtable for sotring key/value pairs
 **/
public class hashTable{
    private final double C = 0.6180340;//inverse of golden ratio
    public int m;
    public LinkedList[] records;
	
	/**
	 *creates a table of size 100
	*/
    public hashTable(){
		this(100);
    }

	/**
	 *create new hashtable of size n
	 */
    public hashTable(int n){
		records = new LinkedList[n];
		for (int i = 0 ; i < records.length ; i++) {
			records[i] = new LinkedList();
		}
		
		m = n;
    }
	
	/**
	 * Inserts a record into the table.
	 */
    public void insert(Record rec){
		records[hash(rec)].addFirst(rec);
    }

	/**
	 * Remove a record from the table.
	 */
    public void delete(int key){
		int index = hash(key);
		LinkedList list = records[index];
		for (int i = 0 ; i < list.size() ; i++) {
			Record r = (Record)list.get(0);
			if (r.key == key) {
			list.remove(i);
			}
		}
    }

	/**
	 *	Search for a record in the table.
	 */
    public Record search(int key){
		return find(key);
    }
	
	/**
	 *	Find a record in the table.
	 */
    private Record find(int key){
		LinkedList list = records[hash(key)];
		for (Object o : list) {
			Record r = (Record)o;
			if (r.key == key) {
			return r;
			}
		}
		return null;
    }

	/**
	 *	Hashing function.
	 */
    public int hash(int key) {
		double val1 = key*C;
		double val2 = Math.floor(key*C);
		double val3 = val1 - val2;
		double val4 = val3 * m;
		
		return (int)Math.floor(val4);
    }

	/**
	 * Hashes a record.
	 */
    private int hash(Record rec){
		return hash(rec.key);
    }
    
	/**
	 *	Removes all records from the table.
	 */
    public void clear() {
		for (LinkedList l : records) {
			l.clear();
		}
    }
    
	/**
	 *	Put a key/value pair into the table.
	 */
    public void put(int key, String value) {
		insert(new Record(key, value));
    }
    
	/**
	 *	Loads all key/value pairs in a file into the table.
	 */
    public void loadFile(String filename) {
		try {
			File file = new File(filename);
			Scanner fileScanner = new Scanner(new FileInputStream(file));
			String line;
			while (fileScanner.hasNext()) {
                line = fileScanner.nextLine();
                int space = line.indexOf(" ");
                String key = line.substring(0, space);
                String value = line.substring(space+1);
                put(Integer.valueOf(key),value);
			}
		} catch (IOException e) {
			System.out.println("Error loading " + filename);
		}
    }
    
	/**
	 *	Save all entries in the dictionary to a file.
	 */
    public void save(String filename) {
		try {
			File file = new File(filename);
			FileWriter fw = new FileWriter(file);
			PrintWriter pw = new PrintWriter(fw);
			for (LinkedList l : records) {
				for (Object o : l) {
					Record r = (Record)o;
					pw.println(r.key + " " + r.value);
				}
			}
			pw.close();
		} catch (IOException e) {
			System.out.println("Error saving the file.");
		}
    }
    
	/**
	 *	Print the whole table.
	 */
    public void print() {
		for (int i = 0 ; i < records.length ; i++) {
			LinkedList l = records[i];
			for (int j = 0 ; j < l.size() ; j++) {
			Record r = (Record)l.get(j);
			System.out.print(i + ": ");
			r.print();
			}
		}
    }
	/**
	 * Runs the program and displays the menu.
	 */
    public static void main(String[] args) {
	
		hashTable ht = new hashTable(178000);
		
		Scanner s = new Scanner(System.in).useDelimiter("\n");
		String in;
		
		boolean running = true;
		while (running) {
			System.out.println("1. Read from file\n2. Insert new entry\n3. Delete entry\n4. Search for entry\n5. Clear whole table\n6. Save table\n7. Quit");
			System.out.print("Enter your choice: ");
			int i = s.nextInt();
			if (i == 1) {
				System.out.print("Load records from file: ");
				in = s.next();
				ht.loadFile(in);
			}
			else if (i == 2) {
				System.out.print("Enter key value pair, seperated with a space: ");
				in = s.next();
				int space = in.indexOf(" ");
				String key = in.substring(0, space);
				String value = in.substring(space+1);
				ht.put(Integer.valueOf(key), value);
			}
			else if (i == 3) {
				System.out.print("Enter key of entry to delete: ");
				in = s.next();
				ht.delete(Integer.valueOf(in));
			}
			else if (i == 4) {
				System.out.print("Enter key: ");
				in = s.next();
				Record r = ht.search(Integer.valueOf(in));
				if (r == null) {
					System.out.println("Record not found.");
				}
				else {
					r.print();
				}
			}
			else if (i == 5) {
				ht.clear();
			}
			else if (i == 6) {
				System.out.print("Filename to save as: ");
					in = s.next();
				ht.save(in);
			}
			else if (i == 7) {
				System.exit(0);
			}
			//ht.print();
		}
		s.close();
    }
}


/**
 *Internal record class
 */
class Record implements Cloneable {
    
    public int key;
    public String value;
    
	/**
	 *	Creates a new record.
	 */
    public Record(int a, String b) {
		key = a;
		value = b;
    }
	
	/**
	 *never used
	 */
    public Object clone(){return new Record(key, value);}
    
	/**
	 *prints the record
	 */
    public void print() {
		System.out.println(key + ":" + value);
    }
}