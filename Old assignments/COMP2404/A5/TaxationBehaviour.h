#ifndef TAXATIONBEHAVIOUR_H
#define TAXATIONBEHAVIOUR_H
#include <string>

class TaxationBehaviour
{
  public:
    virtual float computeTax(float) = 0;

  protected:
    float tax;
};

class Taxable : public TaxationBehaviour
{
  public:
    virtual float computeTax(float price)
    {
      tax = 0.13f;
      return (price*tax);
    }
};

class NonTaxable : public TaxationBehaviour
{
  public:
    virtual float computeTax(float price)
    {
      tax = 0;
      return (price*tax);
    }
};

#endif
