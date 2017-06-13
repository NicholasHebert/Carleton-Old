#ifndef BAKERY_H
#define BAKERY_H
#include <string>
#include "Date.h"
#include "Product.h"
#include "ExpirationBehaviour.h"
#include "TaxationBehaviour.h"


class Bakery : public virtual Product, public virtual Taxable, public virtual Perishable
{
  public:
    Bakery(string n="Unknown", string s="Unknown", int u=0, float p=0.0f, int d=0, int m=1, int y=0, int l=14);
    ~Bakery();
};

#endif
