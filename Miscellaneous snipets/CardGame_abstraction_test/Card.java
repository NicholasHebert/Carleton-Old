package a9;
public class Card extends AbstractCard implements Comparable<Card>{
	public Card(String suit, int rank){
		super(suit, rank);
	}
	public Card(String suit, String rank){
		super(suit, RankToInt(rank));
	}
	public int compareTo(Card other){
		int otherCard = SuitToInt(other.suit);
		int myCard = SuitToInt(this.suit);
		if(otherCard == myCard){
			return 0;
		} else {
			return (otherCard - myCard);
		}
	}
	public String toString(){ 
		return RankToString(this.rank) + " of " + this.suit;
	}
	private int SuitToInt(String currentCard){
		switch (currentCard){
		case "Spades":   return 4;
		case "Hearts":   return 3;
		case "Clubs":    return 2;
		case "Diamonds": return 1;
		default:         return-1;
		}
	}
	private static int RankToInt(String currentCard){
		switch (currentCard){
		case "Joker": return  0;
		case "Ace":   return 14;
		case "Two":   return  2;
		case "Three": return  3;
		case "Four":  return  4;
		case "Five":  return  5;
		case "Six":   return  6;
		case "Seven": return  7;
		case "Eight": return  8;
		case "Nine":  return  9;
		case "Ten":   return 10;
		case "Jack":  return 11;
		case "Queen": return 12;
		case "King":  return 13;
		default:      return -1;
		}
	}
	private static String RankToString(int currentCard){
		switch (currentCard){
		case 0:  return "Joker";
		case 14: return   "Ace";
		case 2:  return   "Two";
		case 3:  return "Three";
		case 4:  return  "Four";
		case 5:  return  "Five";
		case 6:  return   "Six";
		case 7:  return "Seven";
		case 8:  return "Eight";
		case 9:  return  "Nine";
		case 10: return   "Ten";
		case 11: return  "Jack";
		case 12: return "Queen";
		case 13: return  "King";
		default: return "Joker";
		}
	}
}