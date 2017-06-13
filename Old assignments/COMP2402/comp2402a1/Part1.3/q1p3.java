import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.File;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.Scanner;
import java.util.Map;

public class q1p3 {
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
        LinkedHashMap<String, ArrayList<Integer>> map = new LinkedHashMap<String, ArrayList<Integer>>();
        int lineCounter = 0;
        ArrayList<Integer> temp = new ArrayList<Integer>();
        //ArrayList<String> keyHolder = new ArrayList<String>();
        
        for (String line = r.readLine(); line != null; line = r.readLine()) {
            if (map.containsKey(line)){
                temp = map.get(line);
                temp.add(lineCounter);
                map.put(line, temp);
            } else {
                temp = new ArrayList<Integer>();
                temp.add(lineCounter);
                map.put(line, temp);
            }
            lineCounter++;
        }
        
        PrintWriter wComp = new PrintWriter("File1CompFile.txt", "UTF-8");
        PrintWriter wUnComp = new PrintWriter("File1unCompFile.txt", "UTF-8");
        //PrintWriter wResult = new PrintWriter("File1.txt", "UTF-8");
        
        for (Map.Entry<String, ArrayList<Integer>> entry : map.entrySet()){
            wComp.println(entry.getKey());
            wUnComp.println(entry.getValue());
        }
        map.clear();
        wComp.close();
        wUnComp.close();
        
        /*ArrayList<String> resultList = new ArrayList<String>(lineCounter);
        BufferedReader comp, unComp;
        comp = new BufferedReader(new FileReader("File1CompFile.txt"));
        Scanner scan = new Scanner(new File("File1unCompFile.txt"));
        
        for (String line = comp.readLine(); line != null; line = comp.readLine()) {
            keyHolder.add(line);
        }
        
        while (scan.hasNextInt()) {
            temp.add(scan.nextInt());
        }
        
        for (int i = 0; i < temp.size(); i++){
            r.println((temp.get(i));
        }
        for (int i = 0; i < comp.size(); i++){
            for (int j = 0; j < temp.get(i).size(); j++){
                result.add(
            }
        }*/
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
