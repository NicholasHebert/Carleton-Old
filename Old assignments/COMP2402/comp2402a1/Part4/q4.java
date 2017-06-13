import java.io.IOException;
import java.util.Stack;
import java.util.Scanner;

public class q4 {
    /**
     * Read lines one at a time from r.  After reading all lines, output
     * all lines to w, outputting duplicate lines only once.  Note: the order
     * of the output is unspecified and may have nothing to do with the order
     * that lines appear in r.
     * @param r the reader to read from
     * @param w the writer to write to
     * @throws IOException
     */
    public static void doIt(String str) throws IOException {
        Stack square = new Stack();
        Stack curly = new Stack();
        Stack round = new Stack();
        
        for (int i = 0; i < str.length(); i++){
            if (str.charAt(i) == '('){
                round.push(str.charAt(i));
            } else if (str.charAt(i) == '{'){
                curly.push(str.charAt(i));
            } else if (str.charAt(i) == '['){
                square.push(str.charAt(i));
            } else if (str.charAt(i) == '}'){
                curly.pop();
            } else if (str.charAt(i) == ']'){
                square.pop();
            } else if (str.charAt(i) == ')'){
                round.pop();
            }
        }
        
        if (square.empty() && curly.empty() && round.empty()){
            System.out.println("That was a matched String");
        } else {
            System.out.println("That was not a matched String");
        }
    
    }

    
    /**
     * The driver.  Open a BufferedReader and a PrintWriter, either from System.in
     * and System.out or from filenames specified on the command line, then call doIt.
     * @param args
     */
    public static void main(String[] args) {
	    try {
	    Scanner scanner = new Scanner(System.in);
		    System.out.println("Enter a string to test if it is a matched string: \n");
		    String str1 = scanner.nextLine();
		    long start = System.nanoTime();
		    doIt(str1);
		    long stop = System.nanoTime();
		    System.out.println(String.format("%s %,d", "Execution time (Nano seconds): "  , (stop-start)));
	    } catch (IOException e) {
		    System.err.println(e);
		    System.exit(-1);
	    }
    }



}
