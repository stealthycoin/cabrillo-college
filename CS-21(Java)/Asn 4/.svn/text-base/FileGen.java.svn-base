import java.io.File;
import java.io.IOException;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.util.Random;
import java.text.DecimalFormat;

public class FileGen {    
    
    private int lineLength, lineCount;
    
    /**
     *  Creates testing files.
     **/
    public FileGen(int lineLength, int lineCount) {
        this.lineLength = lineLength;
        this.lineCount = lineCount;
    }
    
    /**
     *
     *  Generates a file with the given parameters
     *
     **/
    public void generate(String filename) {
        try {
            File file = new File(filename);
            if (file.createNewFile()) {
                FileWriter fw = new FileWriter(file);
                BufferedWriter bw = new BufferedWriter(fw);
                
                String format = "";
                for (int i = 0 ; i < lineLength ; i++) {
                    format += "0";
                }
                
                DecimalFormat df = new DecimalFormat(format);
                Random rand = new Random();
                
                for (int i = 0 ; i < lineCount ; i++) {
                    int value = rand.nextInt((int)Math.pow(10, lineLength));
                    bw.write(df.format(value));
                    bw.newLine();
                }
                
                bw.close();
            }
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    
    /**
     *
     *  Main method
     *  arg 1 is line length
     *  arg 2 is number of lines
     **/
    public static void main(String[] args) {
        int linelen = 9;
        int numlines = 1000000;
        String filename = "test.txt";
        if (args.length > 2) {
            filename = args[2];
        }
        if (args.length > 1) {
            numlines = Integer.valueOf(args[1]);
        }
        if (args.length > 0) {
            linelen = Integer.valueOf(args[0]);
        }
        
        FileGen fileGen = new FileGen(linelen, numlines);
        fileGen.generate(filename);
    }
}