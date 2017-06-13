#include "Bakery.h"
using namespace std;

Bakery::Bakery(string n, string s, int u, float p, int d, int m, int y, int l) :Product(n,s,u,p,d,m,y,l)
{
  taxPtr = new Taxable;
  expPtr = new Perishable;
  Product::computeExpDate(manD, lifespan);
}
Bakery::~Bakery(){}
