public class CompareStrings {
	static boolean match = false;
	static int WhichChar = 0, regChar = 0;
	static String regEx = "";
	
	public static String toRegex(String w){
		int stringLength = w.length();
		if (regChar == stringLength){
			regEx = regEx + "$";
			return regEx;
		}else if (w.charAt(regChar)== '*'){
			regEx = regEx + ".*";
			regChar ++;
			toRegex(w);
		}else{
			regEx = regEx + w.charAt(regChar);
			regChar ++;
			toRegex(w);
		}
		return regEx;
	}
	
	public static boolean WildcardMatch(String wild, String other) {
		regChar = 0;
		regEx= "^";
		String reg = toRegex(wild);
		if (other.matches(reg)){
			return true;
		} else {
			return false;
		}
	}

	public static boolean match(String x, String y) {
		WhichChar = 0;
		letterMatch(x, y);
		if (match) {
			return true;
		}
		return false;
	}

	public static boolean letterMatch(String a, String b) {
		match = false;
		if (a.length() == 0 || b.length() == 0 ){
			if (a.matches("[*]+")|| b.matches("[*]+")){
				return match = true;
			} else {
				return match = false;
			}
		}
		if (WhichChar == a.length()) {
			return true;
		}
		char c1 = a.charAt(WhichChar), c2 = b.charAt(WhichChar);
		if (c1 == '*') {
			match = WildcardMatch(a, b);
		} 
		if (c2 == '*') {
			match = WildcardMatch(b, a);
		} else if(a.length() != b.length()){
			match = false;
		}  
		if (c1 == c2 || c1 == '@' || c2 == '@' && a.length() == b.length()){
			WhichChar++;
			match =  letterMatch(a, b);
		}
		return match;
	}

	public static void main(String args[]) {
		System.out.println(match("hello", "hello"));
		System.out.println(match("hello", "h@llo"));
		System.out.println(match("hello", "h@@@@"));
		System.out.println(match("hello", "h*"));
		System.out.println(match("hello", "*l*"));
		System.out.println(match("anyString", "*"));
		System.out.println(match("help", "h@@@@"));
		System.out.println(match("help", "h*"));
		System.out.println(match("help", "*l*"));
		System.out.println(match("help", "*l*p"));
		System.out.println(match("help", "h@llo"));
		System.out.println(match("", "*"));
		System.out.println(match("", "***"));
		System.out.println(match("", "@"));

		// I added these test cases on November 25th to ensure that everyone has
		// proper code
		// All should result in false
		System.out.println(match("A", "B"));
		System.out.println(match("ABCD", "ABDC"));
		System.out.println(match("AB", "*C"));
		System.out.println(match("ABCDE", "A*F"));
		System.out.println(match("ABC", "A@D"));
		System.out.println(match("", "*@*"));
	}
}