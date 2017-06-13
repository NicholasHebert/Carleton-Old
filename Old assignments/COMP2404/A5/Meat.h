#ifndef MEAT_H
#define MEAT_H
#include <string>
#include "Date.h"
#include "Product.h"
#include "ExpirationBehaviour.h"
#include "TaxationBehaviour.h"

class Meat : public virtual Product, public virtual Perishable, public virtual NonTaxable
{
  public:
    Meat(string n="Unknown", string s="Unknown", int u=0, float p=0.0f,  int d=0, int m=1, int y=0, int l=14);
    ~Meat();
};

#endif
