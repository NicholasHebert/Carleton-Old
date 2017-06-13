package a9;
/**
 * COMP1406 -  Assignment 9.
 * 
 * @author <Nicholas Hebert>
 * @since <28/3/2016>
 * @custom.citations T.A. Alex Gagnon author of T8-Sample found on CULEARN 
 * 
 */
public class Clothing extends Product{
	//Constructor
	public Clothing(String name, int cost, int[] date){
		super(name, cost, date); //Taken from superclass
	}
	public int sellingPrice(int[] date){
		int[] differenceCal = new int[3];//create calendar from difference between 2 other dates
		float differenceDays = 0;
		for (int i = 0; i < date.length; i++){//fill the difference calendar
			differenceCal[i] = date[i] - this.getPurchaseDate()[i];
		}
		differenceDays =(float)((differenceCal[0]) + (30.42*differenceCal[1]) + (365*differenceCal[2]));//convert that calendar into days
		if (differenceDays <= 365){	
			return Math.round((float)((cost*1.40)*1.13));//cast float to keep precision 
		} else if (differenceDays < 0){
			return -1;	//you can't buy a shirt before it was bought by the store
		} else {
			return Math.round((float)((cost*1.10)*1.13));//cast float to keep precision 
		}
	}
}
