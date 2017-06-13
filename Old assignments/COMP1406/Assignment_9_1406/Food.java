package a9;
/**
 * COMP1406 -  Assignment 9.
 * 
 * @author <Nicholas Hebert>
 * @since <28/3/2016>
 * @custom.citations T.A. Alex Gagnon author of T8-Sample found on CULEARN 
 * 
 */
public class Food extends Product{
	private int[] BestBeforeDate;
	public Food(String name, int cost, int[] Date, int[] bb4) {
		super(name, cost, Date);//taken from super class
		setBestBeforeDate(bb4);
	}
	public Food(String name, int cost, int[] bb4) {
		super(name, cost, bb4);
	}
	public int sellingPrice(int[] date){
		int[] differenceCal = new int[3];//create calendar from difference between 2 other dates
		float differenceDays = 0;
		for (int i = 0; i < date.length; i++){//fill the difference calendar
			differenceCal[i] = this.getPurchaseDate()[i] - date[i];
		}
		
		differenceDays =(float)((differenceCal[0]) + (30.42*differenceCal[1]) + (365*differenceCal[2]));//convert that calendar into days
		if (differenceDays > 0){
			return (int)((float)(cost*2));//cast float to keep precision
		} else {
			return cost;
		}	
	}
	//Getter
	public int[] getBestBeforeDate() {return BestBeforeDate;}
	//Setter
	public void setBestBeforeDate(int[] bestBeforeDate) {
		BestBeforeDate = bestBeforeDate;
	}
}
