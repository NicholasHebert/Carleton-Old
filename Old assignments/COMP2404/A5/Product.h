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

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
#include "Date.h"
#include "ExpirationBehaviour.h"
#include "TaxationBehaviour.h"
using namespace std;

//Class to ensure that all product info is stored
class Product
{
  public:
    Product(string="Unknown", string="Unknown", int=0, float=0.0f, int d=1, int m=1, int y=0, int l=14);
    ~Product();
    int    getId();
    string getName();
    string getSize();
    int    getUnits();
    void   changeUnits(int);
    float  getPrice();
    float  computeTax();
    void   computeExpDate(Date& manufacture, int lifeSpan);
    Date&  getExpDate();
    void   setTax(TaxationBehaviour*);
    void   setExp(ExpirationBehaviour*);

  protected:
    static int nextProdId;
    int        id;
    string     name;
    string     size;
    int        units;
    float      price;
    Date       manD;
    Date       expD;
    int        lifespan;
    ExpirationBehaviour *expPtr;
    TaxationBehaviour   *taxPtr;
};

#endif
