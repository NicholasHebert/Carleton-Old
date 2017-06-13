#include "Meat.h"
using namespace std;

Meat::Meat(string n, string s, int u, float p, int d, int m, int y, int l) :Product(n,s,u,p,d,m,y,l)
{
  taxPtr = new NonTaxable;
  expPtr = new Perishable;
  Product::computeExpDate(manD, lifespan);
}
Meat::~Meat(){}
