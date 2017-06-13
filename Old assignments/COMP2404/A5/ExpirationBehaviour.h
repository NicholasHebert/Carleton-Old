#ifndef EXPIRATIONBEHAVIOUR_H
#define EXPIRATIONBEHAVIOUR_H
#include <string>
#include "Date.h"

class ExpirationBehaviour
{
  public:
    virtual Date computeExpDate(Date&, int) = 0;
};

class NonPerishable : public ExpirationBehaviour
{
  public:
    Date computeExpDate(Date& manufacture, int lifeSpan=730)
    {
      return (manufacture+lifeSpan);
    }
};

class Perishable : public ExpirationBehaviour
{
  public:
    Date computeExpDate(Date& manufacture, int lifeSpan=14)
    {
      return (manufacture+lifeSpan);
    }
};

#endif
