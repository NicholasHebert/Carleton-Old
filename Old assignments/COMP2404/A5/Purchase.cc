#include <string>
#include <cstdlib>

using namespace std;

#include "Purchase.h"

int Purchase::nextPurchId = 6001;

Purchase::Purchase(int i, int u)
{
  id    = i;
  numberUnits = (u >= 0) ? u : 0;
}
Purchase::~Purchase(){}

int    Purchase::getId()    { return id;    }
int    Purchase::getUnits() { return numberUnits; }
void   Purchase::setUnits(){numberUnits++;}
void   Purchase::setId(int prodId){id=prodId;}
