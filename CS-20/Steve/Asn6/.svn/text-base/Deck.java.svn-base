import java.io.*;
import java.util.*;

public class Deck {

	private ArrayDeque<String> deck;
	
	public Deck(String filename) {
		String contents;
		try {
			Scanner s = new Scanner(new FileReader(new File(filename)));
			contents = s.nextLine();
			deck = new ArrayDeque<String>(Arrays.asList(contents.split(" ")));
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public void print() {
		Iterator it = deck.iterator();
		while (it.hasNext()) {
			String element = (String)it.next();
			System.out.print(element + " ");
		}
		System.out.println();
	}
	
}