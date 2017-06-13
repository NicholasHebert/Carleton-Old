package a9;
/**
 * COMP1406 -  Assignment 9.
 * 
 * @author <Nicholas Hebert>
 * @since <28/3/2016>
 * @custom.citations T.A. Alex Gagnon author of T8-Sample found on CULEARN 
 * 
 */
public class FoodWithExpiration extends Food{
	private int[] ExpiryDate;
	public FoodWithExpiration(String name, int cost, int[] date, int[] Expiry) {
		super(name, cost, date);//taken from super class
		ExpiryDate = Expiry;
	}
	public int sellingPrice(int[] date){//this should be self explanatory from the other classes
		int[] differenceCal = new int[3];
		float differenceDays = 0;
		for (int i = 0; i < this.ExpiryDate.length; i++){
			differenceCal[i] = this.ExpiryDate[i] - date[i];
		}
		
		differenceDays =(float)((differenceCal[0]) + (30.42*differenceCal[1]) + (365*differenceCal[2]));
		if (differenceDays <= 1 && differenceDays >=0){
			return Math.round((float)(cost*0.5));
		} else if (differenceDays < 0){
			return -1;
		} else {
			return Math.round((float)(cost*2));
		}
	}
}