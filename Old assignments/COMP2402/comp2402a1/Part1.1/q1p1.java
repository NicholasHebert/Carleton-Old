import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;

public class q1p1 {
    /**
     * Read lines one at a time from r.  After reading all lines, output
     * all lines to w, outputting duplicate lines only once.  Note: the order
     * of the output is unspecified and may have nothing to do with the order
     * that lines appear in r.
     * @param r the reader to read from
     * @param w the writer to write to
     * @throws IOException
     */
    public static void doIt(BufferedReader r, PrintWriter w) throws IOException {
        ArrayList<String> list = new ArrayList<String>();
        // the choice of HashSet is just an illustrative example, you may choose your own implementation choices.
        
        for (String line = r.readLine(); line != null; line = r.readLine()) {
            list.add(line);
            // to enter the null value as a string from the standard input use : ctrl z 
        }

        List<String> list2 = new ArrayList<String>();
        while(!list.isEmpty()){
            if (list.size() > 50){
                for (int i = 49; i>=0; i--){
                    list2.add(list.remove(i));
                    
                }
            } else {
                for (int i = list.size()-1; i>=0; i--){
                    list2.add(list.remove(i));
                }
            }
            for (String text : list2) {
                w.println(text);
            }
                list2.clear();
        }
    }

    
    /**
     * The driver.  Open a BufferedReader and a PrintWriter, either from System.in
     * and System.out or from filenames specified on the command line, then call doIt.
     * @param args
     */
    public static void main(String[] args) {
	    try {
		    BufferedReader r;
		    PrintWriter w;
		    if (args.length == 0) {
			    r = new BufferedReader(new InputStreamReader(System.in));
			    w = new PrintWriter(System.out);
		    } else if (args.length == 1) {
			    r = new BufferedReader(new FileReader(args[0]));
			    w = new PrintWriter(System.out);				
		    } else {
			    r = new BufferedReader(new FileReader(args[0]));
			    w = new PrintWriter(new FileWriter(args[1]));
		    }
		    long start = System.nanoTime();
		    doIt(r, w);
		    w.flush();
		    long stop = System.nanoTime();
		    System.out.println(String.format("%s %,d", "Execution time (Nano seconds): "  , (stop-start)));
	    } catch (IOException e) {
		    System.err.println(e);
		    System.exit(-1);
	    }
    }



}
