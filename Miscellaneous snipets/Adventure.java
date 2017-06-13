import java.util.Scanner;

public class Adventure{    
  Room start = null;
  
  public void initialize(int num){
    // create a game instance with num rooms
    start = AdventureInit.init(num);    
  }
  
  public void play(){
    // play the game
    Scanner keyboard = new Scanner(System.in);
    System.out.print("What is your name? ");
    String s = keyboard.nextLine();
    Player p = new Player(s, 0, 100, "My name is " + s);
    
    Room room = start;
    
    //
    // you need to implement the game
    //
   
    System.out.println( room.getDescription() );
    
    while( p.getHealth() > 0 ){
    
    	if (p.getHealth() <= 20) System.out.println("Your health is getting low, find some food!");
      
      System.out.print( "What do you want to do? ");
      s = keyboard.nextLine().trim().toLowerCase();
      
      System.out.println("You asked to " + s);
      
      if( s.equals("get food") ){
        int f = room.getFood();
        if( f <= 0 ){
          System.out.println("There is no food.");
        }else{
          System.out.println("Yum. That was good. Health increased by " + f);
          p.eatFood(f);
        }      
      }else if( s.equals("get treasure") ){
      	int t = room.getTreasure();
      	if (t <= 0) {
      		System.out.println("There is no treasure");
      	}
      	else {
      		System.out.println("Aww yisssss, got " + t + " gold!");
      		p.collectTreasure(t);
      	}
        p.health -= 10;
      }else if( s.equals("go north") ){
        if( room.exit[0] != null){
          room = room.exit[0];
          System.out.println("Ok, let's go north.");
        }else{
          System.out.println("Really? There is no exit north from here.");
        }
        p.health -= 10;
      }else if( s.equals("go south") ){
        if( room.exit[1] != null){
          room = room.exit[1];
          System.out.println("Ok, let's go south.");
        }else{
          System.out.println("Really? There is no exit south from here.");
        }
        p.health -= 10;
      }else if( s.equals("go east") ){
         if( room.exit[2] != null){
          room = room.exit[2];
          System.out.println("Ok, let's go east.");
        }else{
          System.out.println("Really? There is no exit east from here.");
        }
        p.health -= 10;
      }else if( s.equals("go west") ){
         if( room.exit[3] != null){
          room = room.exit[3];
          System.out.println("Ok, let's go west.");
        }else{
          System.out.println("Really? There is no exit west from here.");
        }
        p.health -= 10;
      }else if( s.equals("go hidden") ){
        if (room.hiddenDoor != null) {
        	room = room.hiddenDoor;
        	System.out.println("Taking the hidden path...");
        }
        else {
        	System.out.println("There is no hidden door here...");
        }
        p.health -= 10;
      }else if( s.equals("where am i") ){
          System.out.println( room.getDescription() );
          if (room.people != null) {
          	for (Player person : room.people) {
          		System.out.println(person.getName() + " says: " + person.ask());
          	}
          }
      }
      

    }
    

	System.out.println(p.getName() + " died, with " + p.getTreasure() + " gold.");    
    
    
  }
  
  
  
  public static void main(String[] args){

    Adventure game = new Adventure();
    
    game.initialize(10);    
    game.play();
    
    
    

    
  }
  
  
  
}   
