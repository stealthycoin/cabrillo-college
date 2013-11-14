import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Program6 {


	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		boolean encrypt;
		String file = null;
		if (args.length == 1 || args.length == 2) {
			if (args[0].equals("d")) {
				encrypt = false;
			}
			else if (args[0].equals("e")) {
				encrypt = true;
			}
			else {
				System.out.println("Please enter either an e or d for encryption or decyrption as the first argument.");
				System.exit(1);
			}
			if (args.length == 2) {
				file = args[1];
			}

		}
		else {
			System.out.println("Incorrect usage.");
			System.exit(1);
		}

		if (file == null) {
			System.out.print("Enter a deck file to enter: ");
			try {
				file = br.readLine();
			}
			catch (IOException e) {
				e.printStackTrace();
			}
		}
		
		Deck deck = new Deck(file);
		
		//input
		try {
			System.out.println("Enter message to be encrypted (non-letters ignored)");
			String message = br.readLine();
			message = message.toUpperCase();
			message = message.replaceAll("[^A-Z]", "");
			
			System.out.println(message);
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
	

}