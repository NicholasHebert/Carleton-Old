#ifndef PURCHASE_H
#define PURCHASE_H

#include <string>
using namespace std;

//Handles purchase information
class Purchase
{
  public:
    Purchase(int, int);
    ~Purchase();
    int    getId();
    int    getUnits();
    void   setUnits();
    void   setId(int);
  protected:
    int id;
    int numberUnits;
    static int nextPurchId;
};

#endif
