
#ifndef PRODLIST_H
#define PRODLIST_H

#include "defs.h"
#include "Product.h"
#include "Date.h"

//Stores information about the Products
class ProdList
{
  class Node
  {
    friend class ProdList;
    public:
      Product* data;
      Node*    next;
      Node*    prev;
  };

  public:
    ProdList();
    ~ProdList();
    void add(Product*);
    void remove(int);
    void reorg();
    int getSize();
    Product* get(int);
    void memFree();

  private:
    Node* head;
    int size;
};

#endif
