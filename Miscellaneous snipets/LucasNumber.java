
public class LucasNumber {
	public static Node lucasNumber(int n){
		if(n==0){Node Head = new Node(2);return Head;}
		if(n==1){Node NextToHead = new Node(1);return null;}
		Node nodeDummy = new Node(lucasNumber(n-1).getLucasNum()+lucasNumber(n-2).getLucasNum());
		return null;
	}
	
	
	
	/*Node head = new Node(2);
	Node node1 = new Node(1);
	
	
	public Node LucasNumber(int n){
	if (n-2<=0){
		return head;
	} else {
		Node newHead = new Node (head.getLucasNum() + head.getNext().getLucasNum());
		newHead.setNext(head);
		head = newHead;
		LucasNumber(n-1);
		return null;
		}
	}*/
}

