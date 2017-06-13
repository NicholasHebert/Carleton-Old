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

#include "Product.h"


int Product::nextProdId = 5001;

Product::Product(string n, string s, int u, float p, int d, int m, int y, int l)
{
  cout << "CTOR in Product" << endl;
  id    = nextProdId++;
  name  = n;
  size  = s;
  units = (u >= 0) ? u : 0;
  price = (p >= 0) ? p : 0;
  manD = Date(d,m,y);
  expD = Date();
  lifespan = l;
}

Product::~Product(){
  cout << "DTOR in Product" <<endl;
}

void   Product::computeExpDate(Date& manufactureDate, int productLifeSpan)
{
  expD = expPtr->computeExpDate(manufactureDate, productLifeSpan);
}

float  Product::computeTax()
{
  return taxPtr->computeTax(price);
}

void   Product::setTax(TaxationBehaviour* t) {taxPtr = t;}
void   Product::setExp(ExpirationBehaviour* e) {expPtr = e;}
int    Product::getId()     { return id;    }
string Product::getName()   { return name;  }
string Product::getSize()   { return size;  }
int    Product::getUnits()  { return units; }
float  Product::getPrice()  { return price; }
void   Product::changeUnits(int input){units+=input;}
Date&  Product::getExpDate() {return expD;}
