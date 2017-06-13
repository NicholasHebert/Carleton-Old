package a9;
/**
 * COMP1406 -  Assignment 9.
 * 
 * @author <Nicholas Hebert>
 * @since <28/3/2016>
 * @custom.citations T.A. Alex Gagnon author of T8-Sample found on CULEARN 
 * 
 */
public class ProcessedFood extends Food{
	private int[] BestBeforeDate;
	public ProcessedFood(String name, int cost, int[] date, int[] bb4) {
		super(name, cost, date);
		BestBeforeDate = bb4;
	}
	public int sellingPrice(int[] date){
		int[] differenceCal = new int[3];
		float differenceDays = 0;
		for (int i = 0; i < date.length; i++){
			differenceCal[i] = this.BestBeforeDate[i] - date[i];
		}
		
		differenceDays =(float)((differenceCal[0]) + (30.42*differenceCal[1]) + (365*differenceCal[2]));
		if (differenceDays > 0){
			return Math.round((float)((cost*2)*1.13));
		} else {
			return Math.round((float)(cost*1.13));
		}
	}
}