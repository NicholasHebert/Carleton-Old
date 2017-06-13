#include "MiscGoods.h"
using namespace std;

MiscGoods::MiscGoods(string n, string s, int u, float p, int d, int m, int y, int l) :Product(n,s,u,p,d,m,y,l)
{
  taxPtr = new NonTaxable;
  expPtr = new NonPerishable;
  Product::computeExpDate(manD, lifespan);
}
MiscGoods::~MiscGoods(){}
