package comp2402a2;

/**
 */
public class Table<T> {
	/**
	 * You decide on the instance variables you need.
	 */

	public Table(Class<T> t) {
		// Put your own code here
		throw new UnsupportedOperationException("Constructor not yet implemented");
	}

	public int rows() {
		// Put your own code here instead of throwing this exception
		throw new UnsupportedOperationException("rows() not yet implemented");
	}

	public int cols() {
		// Put your own code here instead of throwing this exception
		throw new UnsupportedOperationException("cols() not yet implemented");
	}

	public T get(int i, int j) {
		if (i < 0 || i > rows() - 1 || j < 0 || j > cols()-1)
			throw new IndexOutOfBoundsException();
		// Put your own code here instead of throwing this exception
		throw new UnsupportedOperationException("get(i,j) not yet implemented");
	}

	public T set(int i, int j, T x) {
		if (i < 0 || i > rows() - 1 || j < 0 || j > cols()-1)
			throw new IndexOutOfBoundsException();
		// Put your own code here instead of throwing this exception
		throw new UnsupportedOperationException("set(i,j,x) not yet implemented");
	}

	public void addRow(int i) {
		if (i < 0 || i > rows()) throw new IndexOutOfBoundsException();
		// Put your own code here instead of throwing this exception
		throw new UnsupportedOperationException("addRow(i) not yet implemented");
	}

	public void removeRow(int i) {
		if (i < 0 || i > rows() - 1) throw new IndexOutOfBoundsException();
		// Put your own code here instead of throwing this exception
		throw new UnsupportedOperationException("removeRow(i) not yet implemented");
	}

	public void addCol(int j) {
		if (j < 0 || j > cols()) throw new IndexOutOfBoundsException();
		// Put your own code here instead of throwing this exception
		throw new UnsupportedOperationException("addCol(i) not yet implemented");
	}

	public void removeCol(int j) {
		if (j < 0 || j > cols() - 1) throw new IndexOutOfBoundsException();
		// Put your own code here instead of throwing this exception
		throw new UnsupportedOperationException("removeCol(i) not yet implemented");
	}

	public String toString() {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < rows(); i++) {
			for (int j = 0; j < cols(); j++) {
				sb.append(String.valueOf(get(i, j)));
				sb.append(" ");
			}
			sb.append("\n");
		}
		return sb.toString();
	}

	/* Here is the expected output from this main function:
		1111 null null null null null 
		null 2222 null null null null
		null null 3333 null null null
		null null null 4444 null null
		null null null null 5555 null
		null null null null null 6666
		7777 null null null null null
		null 8888 null null null null
		null null 9999 null null null

		1111 null null null null null null
		null 2222 null null null null null
		null null null 3333 null null null
		null null null null null null null
		null null null null 4444 null null
		null null null null null 5555 null
		null null null null null null 6666
		7777 null null null null null null
		null 8888 null null null null null
		null null null 9999 null null null
	*/
	public static void main(String[] args) {
		int nrows = 9, ncols = 6;
		Table<Integer> t = new Table<Integer>(Integer.class);
		for (int i = 0; i < ncols; i++) {
			t.addCol(t.cols());
		}
		for (int i = 0; i < nrows; i++) {
			t.addRow(t.rows());
		}
		for (int i = 1; i <= nrows; i++) {
			t.set(i-1, (i-1)%t.cols(), 1111*i);
		}
		System.out.println(t.toString());
		t.addCol(2);
		t.addRow(3);
		System.out.println(t.toString());
	}
}
