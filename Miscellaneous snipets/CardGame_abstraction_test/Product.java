package a9;

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
