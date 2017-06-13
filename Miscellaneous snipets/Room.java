public class Room{    
  /* attributes */  
  // should be protected or private... but we'll be lazy here
  
  public String description;  // description of the room       
  public Player[] people;     // other players in the room (friend or foe)    
  protected int treasure;     // treasure (value) in the room    
  protected int food;         // food in the room     
  
  public Room[] exit;         // available exits from the room    
  public String[] exitName = {"north", "south", "east", "west"};
  public int    numExits;
  public Room hiddenDoor;     // hidden exit
  
  public Room(String description, int treasure, int food){
    this.description = description;
    this.treasure = treasure;
    this.food = food;
    this.exit = new Room[4];
  }
  
  public String getDescription(){
    String s = description;
    s += " There is an exit to the";    
    int rooms = 0;
    for(int i=0; i< exit.length; i+=1){
      if( exit[i] != null ){
        rooms += 1;
        s += " " + exitName[i];
        if( rooms < numExits ){
          s += ",";
        }else{
          s += ".";
        }
      }
    }
    if( food != 0 ){
      s += " Looks like there is some food here.";
    }
    if( treasure != 0 ){
      s += " Looks like there is something here.";
    }
    if( hiddenDoor != null ){
      if( Math.random() < 0.25 ){
        s += " Looks like there might be a hidden door.";
      }
    }
    if( people != null ){
      s += " There is someone else here.";
    }
    return s;
  }
  
  public int getFood(){
    int f = food/2;
    food = food/2;
    return f;
  }
  
  public int getTreasure(){
    int t = treasure;
    treasure = 0;
    return t;
  }
  
}   