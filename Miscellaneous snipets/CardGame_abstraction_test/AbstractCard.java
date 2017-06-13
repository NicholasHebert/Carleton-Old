package a9;

public abstract class AbstractCard{
 // Use these arrays of Strings for the proper 
 // names of suits and ranks.
  protected static String[] SUITS = new String[]{
    "Spades", "Hearts", "Clubs", "Diamonds"
  };
  protected static String[] RANKS = new String[]{
    "Joker", "Ace", "Two", "Three", "Four", "Five", "Six", 
    "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
  };
  
  
  protected String suit;
  protected int    rank;
  
  /* constructor 
   * 
   * suits are defined by the SUITS array above
   * ranks are as follows: 2 = "Two", 3 = "Three", ..., 10 = "Ten", 
   *                       11 = "Jack", 12 = "Queen", 13 = "King"
   *                       14 = "Ace"
   * 
   * If the suit input is valid but the rank input is invalid 
   * then the card should be created as the Joker of the given suit.
   * 
   * You can always assume that the suit input is valid
   */
  public AbstractCard(String suit, int rank){
    this.suit = suit;
    this.rank = rank;
  }
  
  /* getters */
  public String getSuit(){ return suit; }
  public int    getRank(){ return rank; }
 
 
}