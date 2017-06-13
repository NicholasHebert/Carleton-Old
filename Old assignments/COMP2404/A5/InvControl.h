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

#ifndef INVCONTROL_H
#define INVCONTROL_H

#include "Store.h"
#include "UI.h"
//#include "OrderServer.h"
//#include "OrderArray.h"
#include "Dairy.h"
#include "Bakery.h"
#include "MiscGoods.h"
#include "Meat.h"
#include "CoffeeTea.h"

class InvControl
{
  public:
    InvControl();
    void launch(int, char*[]);
  private:
    Store     store;
    //OrderServer oserver;
    //OrderArray arr;
    UI        view;
    void      initProducts();
    void      initCustomers();
    void      processAdmin();
    void      processCashier();
};
#endif
