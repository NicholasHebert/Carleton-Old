package a9;
/**
 * COMP1406 -  Assignment 9.
 * 
 * @author <Nicholas Hebert>
 * @since <28/3/2016>
 * @custom.citations T.A. Alex Gagnon author of T8-Sample found on CULEARN 
 * 
 */
import java.util.Arrays;

public class TestCards{
  public static void main(String[] args){
    Card[] hand = new Card[52];
    
    // generate a full deck of cards
    int count = 0;
    for(int suit=0; suit<AbstractCard.SUITS.length; suit+=1){
      for(int rank=2; rank<=14; rank+=1){
        hand[count++] = new Card(AbstractCard.SUITS[suit], rank);
      }
    }
    System.out.println( Arrays.toString(hand) );
    
    // shuffle the deck
    for(int i=0; i<hand.length; i++){
      int k = (int) (Math.random()*(hand.length-i));
      // swap card i with card i+k
      Card tmp = hand[i];
      hand[i] = hand[i+k];
      hand[i+k] = tmp;
    }
    System.out.println( Arrays.toString(hand) );
    
    // Sort the deck using the Arrays.sort method.
    // Calling the sort method like this only works because the Card
    // class implements Comparable (it expects to find a compareTo method)
    Arrays.sort(hand);
    System.out.println( Arrays.toString(hand));
    
    //Testing the created classes Card and AbstracCard
    Card c1 = new Card("Hearts", 12); // 12 is for queen
    Card c2 = new Card("Spades", 1); // 1 is not a valid rank
    Card c3 = new Card("Spades", 9); // 9 is for 9
    System.out.println(c1);
    System.out.println(c2);
    System.out.println(c3);
    System.out.println(c1.compareTo(c2) < 0);
    System.out.println(c1.compareTo(c2) > 0);

  }
}