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

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
using namespace std;

#include "Product.h"
#include "PurchArray.h"

//Handles all of the customers information
class Customer
{
  public:
    Customer(string="Unknown");
    ~Customer();
    int    getId();
    string getName();

    //Getters
    int    getPoints();
    float  getCost();
    int    getPurchSize();
    //Setters
    void   setPoints(int);
    void   setCost(float);
    void   addPurchase(Purchase *);
    void   setUnits(int);
    //Getter for PurchArray
    PurchArray getPurchases();

  protected:
    static int nextCustId;
    int        id;
    string     name;
    int        points;
    float      cost;
    PurchArray purchases;
};

#endif
