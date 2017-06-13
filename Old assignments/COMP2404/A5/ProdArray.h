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

#ifndef PRODARRAY_H
#define PRODARRAY_H

#include "defs.h"
#include "Product.h"

//Stores information about the Products
class ProdArray
{
  public:
    ProdArray();
    ~ProdArray();//Destructor Declaration
    void add(Product*);
    void memFree();
    Product& get(int);
    int getSize();
  private:
    Product* elements[MAX_ARR];
    int size;
};

#endif
