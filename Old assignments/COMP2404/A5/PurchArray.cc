#include <string>
#include <cstdlib>

using namespace std;

#include "PurchArray.h"

PurchArray::PurchArray()
{
  cout<<"CTOR in PurchArray"<<endl;
  size = 0;
}

void PurchArray::memFree(){}

PurchArray::~PurchArray()
{
  cout<<"DTOR in PurchArray"<<endl;
  for (int i = 0; i < size; i++){
    free(elements[i]);
  }
  delete(*elements);

}

int PurchArray::getSize() { return size; }
void PurchArray::setUnits(int i) { elements[i]->setUnits();}


Purchase* PurchArray::get(int index)
{
  if (index < 0 || index >= size)
    exit(1);
  return  elements[index];
}

void PurchArray::add(Purchase* purch)
{
  if (size >= MAX_ARR)
    return;
  elements[size++] =purch;
}
