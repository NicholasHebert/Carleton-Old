/**
 * COMP1406 - W16 - Assignment 7.
 * 
 * This class implements a list of people (Person objects)
 * using a linked list. 
 * 
 * @author <Nicholas Hebert>
 * @since <14/03/2016>
 * @custom.citations <http://stackoverflow.com/questions/22605050/reverse-singly-linked-list-java> and resources from 
 * T.A. Alex Gagnon author of T7-Sample found on CULEARN 
 */



public class PersonList{
  /* ----------------------------------------------- */
  /* Attributes                                      */
  /* ----------------------------------------------- */
  
  /* head is the first node in the linked list */
  private Node head;
  
  
  /* ----------------------------------------------- */
  /* constructors                                    */
  /* ----------------------------------------------- */
  
  /** Creates an empty list. */
  public PersonList(){
	  this.head = null;
  }
  
  /** Creates a list with a single person.
* 
* @param p is a Person that will be the only person in the new list
*/ 
  public PersonList(Person p){
	  this.head = new Node (p);
  }
  
  
  /* ----------------------------------------------- */
  /* Methods                                         */
  /* ----------------------------------------------- */
  
  /**
   * The size of the list. 
   * 
   * This is the number of people in the list. If a person
   * is in the list more than once they are counted each time they appear. 
   * For example, the list [sam(12), sam(12), sam(12)] has size 3, even though
   * it is the same person listed three times.
   * 
   * @return the number of people in the list.
   */
  public int size(){
	  int sizeCounter = 0;
	  if (head == null){
		  return 0;
	  }else{
		  for (Node current = this.head; current != null; current = current.getNext()){
			  sizeCounter++;
	      }
		  return sizeCounter; 
	  }
  }
  
  /**
   * Add a person to the front of the list. 
   * 
   * After the method is called, this.head should reference this 
   * newly added person. 
   * 
   * @param p is a person to be added to the front of the list. 
   */
  public PersonList add(Person p){ 
	  Node newHead = new Node(p);
	  if(this.head == null){
		  this.head = newHead;
	  }else{
		  newHead.setNext(this.head);
		  this.head = newHead;			  
	  }
	  return this;
  }
  /**
   * Add a person to a given position in the list.
   * 
   * The indexing is the same as if the list were an array. The first element
   * is at position 0, the second element is at position 1, ..., the last 
   * element is at position this.size()-1.
   * 
   * When adding a person at position M, all people in the original list at positions
   * M, M+1, ..., size()-1, will be shifted over one place (to the right) in the list.
   * If the list was originally [sam(12), joe(17)] and add is called with person 
   * ellen(13) at position 1, then this list becomes [sam(12), ellen(13), joe(17)] 
   *  
   * @param p is a person to add to the list.
   * @param position is the position in the list to add (insert) this person.
   * Positon 0 is the front of the list, position 1 is the 2nd element, etc.
   */
  public PersonList add(Person p, int position){ 
	  if (position == 0){
		  return this.add(p);
	  }
	  if (position > this.size() || position < 0){
		  return this;
	  }
	  int index = 0;
	  Node current = this.head, newNode = new Node(p);
	  while(index != position-1){
		  current = current.getNext();
		  index++;
      }
	  newNode.setNext(current.getNext());
	  current.setNext(newNode);
	  return this; 
  }
  
  /**
   * Adds several people to the list starting at a given position.
   * 
   * For example, if this is the list [cat, dog, eel] and people is
   * the list [one, two , three], then add(people, 0) would change 
   * this be [one, two, three, cat, dog, eel], while add(people,1)
   * would change this list to be [cat, one, two, three, dog, eel].
   * 
   * @param people is a list of people to add to the current list.
   * @param startPosition is the position in the current list that the new 
   * list is added (inserted). The order of the elements in the new list remain
   * the same. 
   */
  public PersonList add(PersonList people, int startPosition){
  	if (people == null){return this;}
  	if (startPosition > this.size()+1){return this;}
  	if (this.head == null){return people;}
  	if (startPosition == 0){
  		Node currentPeople = people.head;
  		Node newTail = this.head;
  		this.head = people.head;
  		while(currentPeople.getNext() != null){
	  		currentPeople = currentPeople.getNext();
	  }
  		currentPeople.setNext(newTail);
  	}
  	else if (startPosition == this.size()){
  		Node newTail = people.head;
  		Node current = this.head;
  		while(current.getNext() != null){
	  		current = current.getNext();
	  }
  		current.setNext(newTail);
  	} else {
  	int indexThis = 0;
  	Node current = this.head;
  	while(indexThis != startPosition){
  		current = current.getNext();
  		indexThis++;
  	}
  	Node NextNode = current.getNext();
  	current.setNext(people.head);
  	while(current.getNext() != null){
  		current = current.getNext();
  	}
  	current.setNext(NextNode);
  	}
  	return this; 
  }
  /**
   * Finds the position in the list where a given person is.
   * 
   * @param p is a person that may or may not be in the list.
   * @return the index position (starting with 0) in the list where the 
   * first instance of of person p is located. (A person may be in the list 
   * more than once.)
   * If the person is not in the list returns -1.
   */
  public int findPosition(Person p){
	  int pos = 0;
	  for (Node current = this.head; current != null; current = current.getNext()){
		if(current.getPerson() == p){
			return pos;  
		}
		pos++;
	 }
  return -1; 
  }
  /** 
   * Finds the person at a given index in the list
   * 
   * You can assume that 0 <= position < this.sise()
   * 
   * @param position is a position in the list. It must satisfy
   * 0 <= position < this.size(). //this sentence makes your last sentence either redundant or you are deliberately trying to confuse your students.
   * @return the person located at the specified position in the list.
   * The method does NOT remove the person from the list.
   */
  public Person personAt(int position){
	  if (position < 0 || position > this.size()){return null;}
	  if (this.head == null){return null;}
	  Node current = this.head;
	  int index = 0;
	  while(index != position){
	  		current = current.getNext();
	  		index++;
	  }
	  return current.getPerson();
  }
  /**
   * Removes a person from a given position in the list.
   * 
   * @param position is the index in the list that we wish to remove a person.
   * @return the person that is removed from the list.
   */ 
  public Person remove(int position){ 
	  if (position < 0 || position > this.size()){return null;}
	  if (this.head == null){return null;}
	  Node current = this.head, removedNode = null;
	  int index = 0;
	  if (position == 0){
		  removedNode = this.head;
		  this.head = current.getNext();
		  return removedNode.getPerson();
	  } else {
		  while(index != position-1){
			  current = current.getNext();
	  		  index++;
		  }
		  removedNode = current.getNext();
		  current.setNext(removedNode.getNext());
		  return removedNode.getPerson(); 
	  }
  }   
  
  /** 
   * remove several people from the list and returns them as a list of people. 
   * 
   * @param startPosition is starting position (index in the list) 
   * of the first person to remove (inclusive).
   * @param endPosition is the ending position (index in the list or one beyond) of the
   * last person EXCLUSIVE. //not removing the last guy from the list.
   * @return a list of people from index position startPosition to endPosition - 1, 
   * in the same order, as this list before the method is called. 
   * The people returned are also removed from the current list.
   */
  public PersonList remove(int startPosition, int endPosition){
  if (startPosition < 0 || startPosition > this.size()){return null;}
  if (endPosition < 0 || endPosition > this.size()){return null;}	  
  if (startPosition > endPosition){return null;}
  if (this.head == null){return null;}
  Node current = this.head;
  PersonList RemovedPeople = new PersonList(); 
  int index = 0;
  if (startPosition == 0){
	  while(index != endPosition){
		  RemovedPeople.add(current.getPerson());
		  current = current.getNext();
		  index++;
	  }
	  this.head = current;
  } else {
	  while(index != startPosition-1){
		  current = current.getNext();
  		  index++;
	  }
	  Node currentRemovedNode = current.getNext();
	  while(index != endPosition){
		  RemovedPeople.add(currentRemovedNode.getPerson());
		  currentRemovedNode = currentRemovedNode.getNext();
		  index++;
	  }
	  current.setNext(currentRemovedNode);
  }
  RemovedPeople.reverseList();
  return RemovedPeople; 
}   
  /** 
   * Checks if this list is the "same" and another list.
   * 
   * Two lists are the same if they have the same people in the same order.
   * Two people are the same if they have the same name (ignoring case) and 
   * the same age. An empty list is not the same as null.
   * 
   * @param otherList is a list of people.
   * @return true if this list contains the same people (none less or more) as the people 
   * in otherList and in the exact same order. 
   * 
   * Returns false otherwise.
   */
  public boolean sameAs(PersonList otherList){ 
	  if (this.size() != otherList.size()){return false;}
	  Node currentOther = otherList.head;
	  for (Node currentThis = this.head; currentThis != null; currentThis = currentThis.getNext()){
		  String p1 = currentThis.getPerson().getName(), p2 = currentOther.getPerson().getName();
		  p1 = p1.toLowerCase();
		  p2 = p2.toLowerCase();
		  if (!p1.equals(p2)){return false;}
		  currentOther = currentOther.getNext();
	  }
	  return true; 
  }
  
  /**
   * A list of all people in this list that have age strictly greater than some cutoff age.
   * 
   * @param age the cutoff age for the output list. //Assuming that the age selected is accepted. (ambiguous parameter)
   * @return a list of all people in this list that have age strictly greater than the input cutoff age.
   * The order of the people in the returned list is the same as in this list. 
   * This method does NOT remove any people from this list.
   */
  public PersonList olderThan(int age){ 
	  PersonList PeopleWhoAreOldNuff = new PersonList(); 
	  for (Node current = this.head; current != null; current = current.getNext()){
		  if (current.getPerson().getAge() >= age){
			  PeopleWhoAreOldNuff.add(current.getPerson());
		  }
	  }
	  return PeopleWhoAreOldNuff; 
  }
  
  /**
   * A String representation of this list. 
   * 
   * If this list consists of the people
   * [cat age 12, dog age 17, eel age 3], the output string should look identical 
   * (without the double quotes) to "[cat(12), dog(17), eel(3)]". An empty list will
   * return "[]". Be sure not to have a trailing comma after the last person 
   * in the list.
   * 
   * @return a string representation of this list.
   */
  @Override
  public String toString(){ 
	  if (this.head == null){return "[]";
	  } else {
	  String returningValue = "[";
	  for (Node current = this.head; current != null; current = current.getNext()){
		  if (current == this.head){
			  returningValue += current.getPerson().getName() + "(" + current.getPerson().getAge() + ")";
		  } else {
			  returningValue += ", " + current.getPerson().getName() + "(" + current.getPerson().getAge() + ")";
		  }
	  }
	  returningValue += "]";
	  return returningValue; 
	  }
  }
  /**
   * http://stackoverflow.com/questions/22605050/reverse-singly-linked-list-java
   * I used this thread from stackoverflow to understand how to efficiently reverse the order of a linked list
   * Author:Joop Eggen
   * 
   * This method reverses the order of a linked list
   */
  public void reverseList(){	  
	  Node back = null;
	  Node current = this.head;
	  while (current != null) {
	      Node next = current.getNext();
	      current.setNext(back);
	      back = current;
	      current = next;
	  }
	  this.head = back;
  }
}

