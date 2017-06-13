public class Player{    
  
  protected String name; 
  protected String message;
  protected int treasure = 0;
  protected int health = 100;
  
  public Player(String name, int treasure, int health, String message){
    this.name = name;
    this.treasure = treasure;
    this.health = health;
    this.message = message;
   }
 
  public String ask(){
    return message;
  }
  
  public void eatFood(int f){
    health += f;
  }
  
  public void collectTreasure(int amount) {
  	treasure += amount;
  }
  
  public int getHealth(){ return health; }
  public int getTreasure(){ return treasure; }
  public String getName() { return name; }
  
  public void decreaseHealth() { health -= 10; }
  
}   
