/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Inventory System              */
/*  Author:   Christine Laurendeau                 */
/*  Date:     28-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */
#include <iostream>
using namespace std;
#include <cstdlib>
#include "InvControl.h"
#include "Store.h"
//#include "Order.h"
//#include "OrderServer.h"
//#include "OrderArray.h"

InvControl::InvControl()
{
  initProducts();
  initCustomers();
}

void InvControl::launch(int argc, char* argv[])
{
  if (argc != 2) {
    view.printUsageError();
    exit(1);
  }

  string option(argv[1]);

  if (option == "-a") {		// Admin menu
    processAdmin();
  }
  else if (option == "-c") {	// Cashier menu
    processCashier();
  }
  else {
    view.printUsageError();
    exit(1);
  }
}

void InvControl::processAdmin()
{
    int    choice;
    string prodName, prodSize;
    int    prodUnits, prodId, amount;
    float  prodPrice;

    int typeChoice = -1;

    while (1) {
        choice = -1;
        view.adminMenu(choice);
        if (choice == 1) {
            while (typeChoice < 1 || typeChoice > 5){
                cout << "What product Category Does Your Product Fall Under?" << endl;
                view.promptForInt("Meat[1], Coffee/Tea[2], Dairy [3], Bakery[4], Miscellaneous Goods [5]", typeChoice);
                if (typeChoice == 1){
                    view.promptForStr("Product name", prodName);
                    view.promptForStr("Product size", prodSize);
                    view.promptForInt("# units", prodUnits);
                    view.promptForFloat("Price", prodPrice);
                    Meat* prod01 = new Meat (prodName, prodSize, prodUnits, prodPrice);
                    store.addProd(prod01);
                    view.pause();
                } else if(typeChoice ==2){
                    view.promptForStr("Product name", prodName);
                    view.promptForStr("Product size", prodSize);
                    view.promptForInt("# units", prodUnits);
                    view.promptForFloat("Price", prodPrice);
                    CoffeeTea* prod01 = new CoffeeTea (prodName, prodSize, prodUnits, prodPrice);
                    store.addProd(prod01);
                    view.pause();
                } else if(typeChoice ==3){
                    view.promptForStr("Product name", prodName);
                    view.promptForStr("Product size", prodSize);
                    view.promptForInt("# units", prodUnits);
                    view.promptForFloat("Price", prodPrice);
                    Dairy* prod01 = new Dairy (prodName, prodSize, prodUnits, prodPrice);
                    store.addProd(prod01);
                    view.pause();
                } else if(typeChoice ==4){
                    view.promptForStr("Product name", prodName);
                    view.promptForStr("Product size", prodSize);
                    view.promptForInt("# units", prodUnits);
                    view.promptForFloat("Price", prodPrice);
                    Bakery* prod01 = new Bakery (prodName, prodSize, prodUnits, prodPrice);
                    store.addProd(prod01);
                    view.pause();
                } else if(typeChoice ==5){
                    view.promptForStr("Product name", prodName);
                    view.promptForStr("Product size", prodSize);
                    view.promptForInt("# units", prodUnits);
                    view.promptForFloat("Price", prodPrice);
                    MiscGoods* prod01 = new MiscGoods (prodName, prodSize, prodUnits, prodPrice);
                    store.addProd(prod01);
                    view.pause();
                } else {
                    cout << "INVALID CATEGORY CHOICE! " << endl;
                    view.promptForInt("Meat[1], Coffee/Tea[2], Dairy [3], Bakery[4], Miscellaneous Goods [5]", typeChoice);
                }
            }
        }

        else if (choice == 2) {	// add inventory
            int prodId, quant, run;
            view.promptForInt("Input Product ID", prodId);
            view.promptForInt("Input Quantity", quant);
            run= store.addInv(prodId, quant);
            while(run!=0){
                view.promptForInt("Invalid. Re-enter Product ID", prodId);
                view.promptForInt("Input Quantity", quant);
                run= store.addInv(prodId, quant);
            }
            prodId=0;
            quant=0;
            run=0;
        }
        else if (choice == 3) {	// print inventory
            view.printStock(store.getStock());
            view.pause();
        }
        else if (choice == 4) {	// print customers
            view.printCustomers(store.getCustomers());
            view.pause();
        }
        else if (choice == 5) {	// remove inventory
            int prodId, run;
            view.promptForInt("Input Product ID", prodId);
            run= store.remInv(prodId);
            while(run!=0){
                view.promptForInt("Invalid. Re-enter Product ID", prodId);
                run= store.remInv(prodId);
            }
            prodId=0;
            run=0;
        }
        else {
            store.freeAll();
            break;
        }
    }
}

void InvControl::processCashier()
{
  int choice;
  int purchUnits, prodId, custId;
  int otherid = 100;
  int run2 = 1;

  while (1) {
    choice = -1;
    view.cashierMenu(choice);
    if (choice == 1) {			// purchases
      view.promptForInt("Customer ID", custId);
      //cust id errorcheck
      while (otherid == 100){
        otherid = store.validID(custId);
        if (otherid==100){
	      view.promptForInt("Invalid. Re-enter Customer ID", custId);
	    }
      }

      //Create New Order Here


      view.promptForInt("Input Product ID", prodId);
      run2 = store.validProd(prodId, otherid);

      //Extra Error Checking!
      while (run2 !=0){
        run2 = store.validProd(prodId, otherid);
        if (run2==2){
          view.promptForInt("This product is out of stock. Enter a different Product ID", prodId);
        }
        if (run2==1){
          view.promptForInt("Invalid. Re-enter Product ID", prodId);
        }
      }
      otherid=100;
      run2=1;
    }


    else if (choice == 2) {		// return purchases
      view.printError("Feature not implemented");
    }
    else if (choice == MAGIC_NUM) {	// print inventory and customers
      view.printStock(store.getStock());
      view.printCustomers(store.getCustomers());
      //oserver.retrieve(arr);
      //view.printStr(arr);
      view.pause();
    }
    else {
      store.freeAll();
      break;
    }
  }
}

void InvControl::initProducts()
{


  MiscGoods * prod01 = new MiscGoods ("Sudzzy Dish Soap", "1 L", 10, 3.99f);
  store.addProd(prod01);

  MiscGoods * prod02 = new MiscGoods("Peachy Laundry Soap", "2 L", 3, 8.99f);
  store.addProd(prod02);

  MiscGoods * prod03 = new MiscGoods("Daisy's Spicy Chili", "150 g", 5, 1.29f);
  store.addProd(prod03);

  MiscGoods * prod04 = new MiscGoods("Daisy's Maple Baked Beans", "220 g", 2, 2.49f);
  store.addProd(prod04);

  Meat * prod05 = new Meat("Marmaduke Hot Dogs", "12-pack", 4, 4.99f);
  store.addProd(prod05);

  Meat * prod06 = new Meat("Garfield Hamburger Patties", "900 g", 2, 11.99f);
  store.addProd(prod06);

  Dairy * prod07 = new Dairy("Chunky Munkey Ice Cream", "2 L", 1, 2.97f);
  store.addProd(prod07);

  Dairy * prod08 = new Dairy("It's Your Bday Chocolate Cake", "500 g", 0, 12.99f);
  store.addProd(prod08);

  Bakery * prod09 = new Bakery("Happy Baker's Hot dog buns", "12-pack", 5, 3.49f);
  store.addProd(prod09);

  Bakery * prod10 = new Bakery("Happy Baker's Hamburger buns", "8-pack", 8, 3.99f);
  store.addProd(prod10);

  Dairy * prod11 = new Dairy("Moo-cow 2% milk", "1 L", 7, 2.99f);
  store.addProd(prod11);

  Dairy * prod12 = new Dairy("Moo-cow 2% milk", "4 L", 3, 4.99f);
  store.addProd(prod12);

  Dairy * prod13 = new Dairy("Moo-cow 5% coffee cream", "250 ml", 4, 1.49f);
  store.addProd(prod13);

  MiscGoods * prod14 = new MiscGoods("Good Morning Granola Cereal", "400 g", 2, 5.49f);
  store.addProd(prod14);

  CoffeeTea * prod15 = new CoffeeTea("Lightening Bolt Instant Coffee", "150 g", 8, 4.99f);
  store.addProd(prod15);

  CoffeeTea * prod16 = new CoffeeTea("Lightening Bolt Decaf Coffee", "100 g", 2, 4.99f);
  store.addProd(prod16);

  MiscGoods * prod17 = new MiscGoods("Munchies BBQ Chips", "250 g", 7, 2.99f);
  store.addProd(prod17);

  MiscGoods * prod18 = new MiscGoods("Munchies Ketchup Chips", "250 g", 3, 2.99f);
  store.addProd(prod18);

  MiscGoods * prod19 = new MiscGoods("Dogbert Salted Chips", "210 g", 4, 1.99f);
  store.addProd(prod19);

  MiscGoods * prod20 = new MiscGoods("Dogbert Sweet and Spicy Popcorn", "180 g", 5, 2.29f);
  store.addProd(prod20);

}

void InvControl::initCustomers()
{
  Customer * cust01 = new Customer("Starbuck");
  Customer * cust02 = new Customer("Apollo");
  Customer * cust03 = new Customer("Boomer");
  Customer * cust04 = new Customer("Athena");
  Customer * cust05 = new Customer("Helo");
  Customer * cust06 = new Customer("Crashdown");
  Customer * cust07 = new Customer("Hotdog");
  Customer * cust08 = new Customer("Kat");
  Customer * cust09 = new Customer("Chuckles");
  Customer * cust10 = new Customer("Racetrack");

  store.addCust(cust01);
  store.addCust(cust02);
  store.addCust(cust03);
  store.addCust(cust04);
  store.addCust(cust05);
  store.addCust(cust06);
  store.addCust(cust07);
  store.addCust(cust08);
  store.addCust(cust09);
  store.addCust(cust10);
}
