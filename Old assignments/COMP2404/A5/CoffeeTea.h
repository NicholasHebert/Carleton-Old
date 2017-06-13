#ifndef COFFEETEA_H
#define COFFEETEA_H
#include <string>
#include "Date.h"
#include "Product.h"
#include "ExpirationBehaviour.h"
#include "TaxationBehaviour.h"

class CoffeeTea : public virtual Product, public virtual NonPerishable, public virtual Taxable
{
  public:
    CoffeeTea(string n="Unknown", string s="Unknown", int u=0, float p=0.0f, int d=0, int m=1, int y=0, int l=730);
    ~CoffeeTea();
};

#endif
