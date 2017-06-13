public class Node{
  private int lucas;
  private Node   next;
  
  /* constructors */

  /** Create an empty node */
  public Node(){
    this.lucas = -1;
    this.next = null;
  }

  /** Create a node with person specified by name and age */
  public Node(int newLucas){
    this.lucas = newLucas;
    this.next = null;
  }
  
  /* getters */
  
  /** Date getter (Person) */
  public int getLucasNum(){ return this.lucas; }
  
  /** Next node getter */
  public Node getNext(){ return this.next; }
  
  
  /* setters */
  
  /** Person setter */
  public void setLucas(int lucas){ this.lucas = lucas; }
  
  /** Next node setter */
  public void setNext(Node next){ this.next = next; }
	
}
