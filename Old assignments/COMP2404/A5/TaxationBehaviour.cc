#include "TaxationBehaviour.h"

float TaxationBehaviour::computeTax(float price)
{
  tax = 0.13f;
  return (price*tax);
}
