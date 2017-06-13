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
#include "Store.h"

void Store::freeAll(){
  stock.memFree();
  for (std::list<Customer*>::iterator itr = customers.begin(); itr != customers.end(); itr++){
    (*itr)->getPurchases().memFree();
    delete(*itr);
  }
  customers.clear();
}

ProdList Store::getStock()     { return stock; }
list<Customer*> Store::getCustomers() { return customers; }

int Store::remInv (int prodId){
  int x=0;
  while (x<stock.getSize()){
    Product* y=stock.get(x);
    if (prodId ==y->getId()){
      stock.remove(x);
      stock.reorg();
      return 0;
    }
  x++;
  }
  return 1;
}

int Store::addInv(int prodId, int quantity){
  int x=0;
  while (x<stock.getSize()){
    Product* y=stock.get(x);
    if (prodId ==y->getId()){
      stock.get(x)->changeUnits(quantity);
      return 0;
    }
  x++;
  }
  return 1;
}
void Store::addProd(Product* prod)
{
  stock.add(prod);
}

void Store::addCust(Customer* cust)
{
  customers.push_back(cust);
}
//function to error check customer's id's
int Store::validID(int id)
{
  for (std::list<Customer*>::iterator itr = customers.begin(); itr != customers.end(); itr++){
    if ((*itr)->getId() == id){
      return ((*itr)->getId());
    }
  }
  return 100;
}

Customer& Store::getCust(int id)
{
  for (std::list<Customer*>::iterator itr = customers.begin(); itr != customers.end(); itr++){
    if ((*itr)->getId() == id){
      return (*(*itr));
    }
  }
}

//function to error check produt id's and set purches
int Store::validProd(int prod, int custId)
{
  int z;
  float j;
  int x = 0;
  int t = 0;
  int repeat = 0;
  while (x < stock.getSize()){
	Product *y =stock.get(x);
	if (prod == y->getId()){
	   if(y->getUnits() <= 1){ return 2; }
	   stock.get(x)->changeUnits(-1);
        stock.reorg();
	   j = stock.get(x)->getPrice();
	   getCust(custId).setCost(j);
	   cout <<"Cost: " << getCust(custId).getCost()<<endl;
	   z = int (round(j));
	   getCust(custId).setPoints(z);
           cout<<"Loyalty Points: " << getCust(custId).getPoints()<<endl;
	   while (t < getCust(custId).getPurchases().getSize()){
	     Purchase* b= getCust(custId).getPurchases().get(t);
	     if(b->getId() == prod){
	       getCust(custId).setUnits(t);
	       repeat = 1;
           break;
	     }
  	     t++;
	   }
	   if(repeat!=1){
         Purchase * prod2 = new Purchase(prod, 1);
         getCust(custId).addPurchase(prod2);
       }
      return 0;
	}
    x++;
  }
  return 1;
}
