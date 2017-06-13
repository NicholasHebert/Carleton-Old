#ifndef PURCHARRAY_H
#define PURCHARRAY_H

#include "defs.h"
#include "Purchase.h"
#include <iostream>
using namespace std;

//Handles all important purchase information
class PurchArray
{
  public:
    PurchArray();
    ~PurchArray();//Destructor Declaration
    void add(Purchase*);
    Purchase* get(int);
    int getSize();
    void memFree();
    void setUnits(int);
  private:
    Purchase *elements[MAX_ARR];
    int size;
};

#endif
