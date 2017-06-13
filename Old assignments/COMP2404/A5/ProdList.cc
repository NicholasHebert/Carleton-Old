#include <string>
#include <cstdlib>

#include <iostream>
using namespace std;
#include "ProdList.h"

ProdList::ProdList(){
    cout << "CTOR in ProdList" << endl;
    head=NULL;
    size=0;
}

ProdList::~ProdList(){

}

void ProdList::memFree()
{
    //this function is based off destructor seen in class
    Node* currNode = head;
    Node* temp;
    while (currNode != NULL) {
      cout << "DTOR in ProdList" <<endl;
      temp = currNode->next;
      //free(currNode->data);
      delete(currNode);
      currNode = temp;
    }
}

Product* ProdList::get(int i)
{
    Node* currNode = head;
    for(int x=0; x<i; x++)
    {
        currNode = currNode->next;
    }
    return currNode->data;
}

int ProdList::getSize(){return size;}



void ProdList::add(Product* p)
{
    //this function is based off add function seen in class
    Node* prodNode;
    Node* currNode;
    Node* temp;
    prodNode = new Node;
    prodNode->data = p;
    prodNode->next = NULL;
    prodNode->prev = NULL;
    size++;
    currNode = head;
    temp = NULL;

    while (currNode != NULL) {
        //if (prodNode->data->getExpDate() < currNode->data->getExpDate()){break;}
        if (prodNode->data->getUnits() < currNode->data->getUnits()){break;}
        temp = currNode;
        currNode = currNode->next;
    }

    if (temp == NULL) {	// add to beginning
        head = prodNode;
    }
    else {
        temp->next = prodNode;
        prodNode->prev = temp;
    }
    prodNode->next = currNode;
}

void ProdList::remove(int id)
{
    size--;
    Node* currNode = head;
    while (currNode != NULL) {
        if (currNode->data->getId() == id)
        {
            if(currNode->prev==NULL)
            {
                head = currNode->next;
                currNode->next->prev =NULL;
            }
            else
            {
                currNode->next->prev=currNode->prev;
                currNode->prev->next=currNode->next;
            }
            delete currNode;
            break;
        }
        currNode = currNode->next;
    }

}

void ProdList::reorg()
{
    int count = 0, i;
    Node *initialNode = head;
    Node *currNode = NULL;
    Node *prevNode = NULL;
    Node *nextNode = NULL;

    while(initialNode != NULL) { //Count how many nodes there are.
        count++;
        initialNode = initialNode->next;
    }

    for(i = 0; i<count; ++i) {

        currNode = prevNode = head; //set currNode and prevNode at the start node

        while (currNode->next != NULL) { //for the rest of the elements
            //Check currNode's Number of Units vs. currNode->next's Number Of Units
            //if (prodNode->data->getExpDate() < currNode->data->getExpDate()){break;}
            if (currNode->data->getExpDate() > currNode->next->data->getExpDate())
            {
                //Exchange the pointers for currNode and currNode->next
                nextNode = currNode->next;
                currNode->next = nextNode->next;
                nextNode->next = currNode;

                if(currNode == head)
                    head = prevNode = nextNode;
                else //setup prevNode correctly
                    prevNode->next = nextNode;
                //Now make currNode become nextNode since they aren't at the same position anymore
                currNode = nextNode;
            }
            //In currNode Units are not Greater than currNode->next's Units Traverse On
            prevNode = currNode;
            currNode = currNode->next;
        }
    }
}
