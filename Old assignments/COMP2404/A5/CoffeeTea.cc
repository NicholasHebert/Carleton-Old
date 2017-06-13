#include "CoffeeTea.h"
using namespace std;

CoffeeTea::CoffeeTea(string n, string s, int u, float p, int d, int m, int y, int l) :Product(n,s,u,p,d,m,y,l)
{
  taxPtr = new Taxable;
  expPtr = new NonPerishable;
  Product::computeExpDate(manD, lifespan);
}
CoffeeTea::~CoffeeTea(){}
