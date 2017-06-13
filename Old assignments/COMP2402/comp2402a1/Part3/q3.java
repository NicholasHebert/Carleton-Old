import java.io.IOException;
import java.util.Stack;

public class q3 {
    /**
     * Read lines one at a time from r.  After reading all lines, output
     * all lines to w, outputting duplicate lines only once.  Note: the order
     * of the output is unspecified and may have nothing to do with the order
     * that lines appear in r.
     * @param r the reader to read from
     * @param w the writer to write to
     * @throws IOException
     */
    public static void doIt() throws IOException {
        int[] good = {1, -1, 1, 1, -1, 1, -1, 1, 1};
        int[] bad = {1, -1, -1, 1, -1, 1, -1};
        Stack dyckStk = new Stack();
        for (int i = 0; i < good.length; i++){
            dyckStk.push(good[i]);
        }
        test(dyckStk);
        dyckStk.clear();
        for (int i = 0; i < bad.length; i++){
            dyckStk.push(good[i]);
        }
        test(dyckStk);
        dyckStk.clear();
    }
    
    static void test(Stack stk) throws IOException {
        int count = 0, dyck = 0;
        
        while (!stk.empty()){
            dyck += (int) stk.pop();
            count++;
            if (dyck < 0 && count > 0){break;}
        }
        
        if (dyck < 0){
            System.out.println("That was not a Dyck: " + dyck);
        } else {
            System.out.println("That was a Dyck: " + dyck);
        }
    }

    
    /**
     * The driver.  Open a BufferedReader and a PrintWriter, either from System.in
     * and System.out or from filenames specified on the command line, then call doIt.
     * @param args
     */
    public static void main(String[] args) {
	    try {
		    long start = System.nanoTime();
		    doIt();
		    long stop = System.nanoTime();
		    System.out.println(String.format("%s %,d", "Execution time (Nano seconds): "  , (stop-start)));
	    } catch (IOException e) {
		    System.err.println(e);
		    System.exit(-1);
	    }
    }



}
