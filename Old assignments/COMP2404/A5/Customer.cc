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

#include <cmath>
#include "Customer.h"
#include "PurchArray.h"


int Customer::nextCustId = 2001;

Customer::Customer(string n)
{
  id     = nextCustId++;
  name   = n;
  points = 0;
  PurchArray* purchases;
  cout<<"CTOR in Customer" <<endl;
}

Customer::~Customer()
{
  cout<<"DTOR in Customer" <<endl;
}

//Getters
int    Customer::getId()      { return id;    }
string Customer::getName()    { return name;  }
int    Customer::getPoints()  { return points;}
float  Customer::getCost()    { return cost;  }
int    Customer::getPurchSize() {return purchases.getSize();}
PurchArray Customer::getPurchases() { return purchases; }

//Add & Set Units
void   Customer::addPurchase(Purchase* i) {
  purchases.add(i);
}
void   Customer::setUnits(int index){purchases.setUnits(index);}

//Function to set points
void   Customer::setPoints(int newPoints){
	points+=newPoints;
}
void   Customer::setCost(float newCost){
	cost+=newCost;
}
