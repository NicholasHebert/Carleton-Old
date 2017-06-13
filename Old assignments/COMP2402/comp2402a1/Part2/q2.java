import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.PriorityQueue;

public class q2 {
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
 
        PriorityQueue<String> que = new PriorityQueue<String>();
        
        for (String line = r.readLine(); line != null; line = r.readLine()) {
            que.add(line);
        }

        while (que.size()>0){
            w.println(que.poll());
        }
        if (que.peek() == null){
            w.println("The priority queue is now empty");
        } else {
            w.println("Something went wrong, the queue still has objects within it");
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
