package a9;
/**
 * COMP1406 -  Assignment 9.
 * 
 * @author <Nicholas Hebert>
 * @since <28/3/2016>
 * @custom.citations T.A. Alex Gagnon author of T8-Sample found on CULEARN 
 * 
 */
import java.math.*;
@SuppressWarnings("unused")
public abstract class Product{
   protected String name;      // name of product
   protected int    cost;      // cost of the product from manufacturer (in cents)
   protected int[]  date;      // date of purchase from manufacturer [day, month, year] 

   /* constructor */
   public Product(String name, int cost, int[] date){
     this.name = name;
     this.cost = cost; 
     this.date = date; 
   }
   public int sellingPrice(int[] date){
     return cost;
   }
   
  /* getters */
   public String getName(){ return name; }
   public int    getCost(){ return cost; }
   public int[]  getPurchaseDate(){ return date; }
   
}
