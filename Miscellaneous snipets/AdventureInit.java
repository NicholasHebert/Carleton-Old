public class AdventureInit{    
  
  public static Room init(int numRooms){
    // create a game with numRooms rooms in it
    
    // main entrance
    Room start = new Room("You are in the main entrence of the castle.", 0, 20);
    start.people = new Player[]{ new Player("Butler", 0, 0, "Welcome.  Please have a look around and enjoy your visit.") };
    
    //						C			D
    //						|
    //				 B--S	 A			
    //						|	 |
    //						H--L--K
    //							 |
    //							 T
    							 
    start.numExits = 3;
    start.exit[0] = new Room("You are in the coat room.", 10, 0);
    start.exit[0].exit[1] = start; // these rooms are connected
    start.exit[0].numExits = 1;
      
    start.exit[1] = new Room("You are in the main hallway.", 0, 0);
    start.exit[1].exit[0] = start; // these rooms are connected
    start.exit[1].numExits = 1;
    
    start.exit[3] = new Room("A bathroom, yuck!", 0, 0);
    start.exit[3].exit[2] = start; // these rooms are connected
    start.exit[3].numExits = 2;
  
  	//make some new rooms
  	Room lounge = new Room("A cozy lounge, with some cookies by the fire.", 10, 10);
  	Room armory = new Room("A collection of weapons.", 0, 0);
  	Room kitchen = new Room("MMM, smells delicious! Must be the kitchen...", 0, 30);
  	Room treasury = new Room("Stacks and stacks of gold pieces! The Treasury!", 30, 0);
  	Room dungeon = new Room("The DUNGEON, there are piles of human bones.", 0, 0);
  	dungeon.people = new Player[] { new Player("Dungeon master", 0, 0, "You aren't supposed to be in here...")};
  	
  	lounge.numExits = 4;
  	
  	//handles for rooms already made
  	Room hallway = start.exit[1];
    Room closet = start.exit[3];
    
    hallway.exit[2] = lounge;
    lounge.exit[3] = hallway;
    
    lounge.exit[0] = armory;
    armory.exit[1] = lounge;
    armory.numExits = 1;
    
    lounge.exit[2] = kitchen;
    kitchen.exit[3] = lounge;
    kitchen.numExits = 1;
    
    lounge.exit[1] = treasury;
    treasury.exit[0] = lounge;
    treasury.numExits = 1;
    
    lounge.hiddenDoor = dungeon;
    dungeon.hiddenDoor = lounge;
    
    return start;
  }
  
  
}   
