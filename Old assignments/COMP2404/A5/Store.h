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

#ifndef STORE_H
#define STORE_H
#include <math.h>
#include "ProdList.h"
#include "Product.h"
#include <list>
#include <iterator>
#include <algorithm>
#include "Customer.h"


//Pretty Much does everything
//Error Checking
//Makes sure that both ID and Products are actually Valid

class Store
{
  public:
    void       addProd(Product*);
    void       addCust(Customer*);
    ProdList   getStock();
    void       freeAll();
    int        validID (int);
    int        addInv(int, int);
    int        validProd(int, int);
    int        remInv(int);
    list<Customer*>getCustomers();
    Customer&  getCust(int);
  private:
    ProdList  stock;
    list<Customer*> customers;
};

#endif
