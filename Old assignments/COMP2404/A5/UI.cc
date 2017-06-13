/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Inventory System              */
/*  Author:   Christine Laurendeau                 */
/*  Date:     28-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "UI.h"
using namespace std;


void UI::adminMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   INVENTORY MANAGEMENT SYSTEM ADMIN MENU\n\n";
  cout<< "          1. Add new product \n\n";
  cout<< "          2. Add more inventory \n\n";
  cout<< "          3. Print inventory \n\n";
  cout<< "          4. Print customers \n\n";
  cout<< "          5. Remove product \n\n";
  cout<< "          6. Print orders \n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 6) {
    cout << "Enter your selection:  ";
    choice = readInt();
  }
}

void UI::cashierMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   INVENTORY MANAGEMENT SYSTEM CASHIER MENU\n\n";
  cout<< "          1. Product purchases\n\n";
  cout<< "          2. Product returns\n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 2) {
    cout << "Enter your selection:  ";
    choice = readInt();
    if (choice == MAGIC_NUM) return;
  }
}

void UI::printStock(ProdList arr)
{
  // The stringstream class helps us convert from numeric values to string.
  // The I/O manipulation functions help us make the output look pretty.

  stringstream ss;

  cout << endl << "STOCK: " << endl << endl;
  cout << " ID                                 Name             Size    Qty    Price      Expires on" << endl;
  cout << " --                                 ----             ----    ---    -----      ----------" << endl;

  for (int i=0; i<arr.getSize(); i++) {

    Product * prod = arr.get(i);

    cout << prod->getId()   << "  " << setw(40) << prod->getName() << "  "
         << setw(10) << prod->getSize() << "  " << setw(4)  << prod->getUnits() << "    ";

    ss << setw(6) << fixed << setprecision(2) << prod->getPrice();

    cout << "$" << ss.str() << "    " << prod->getExpDate().toString();
    ss.str("");
  }
}

void UI::printCustomers(list<Customer*> list)
{
  list.sort();
  cout << endl << "CUSTOMERS: " << endl << endl;

  for (std::list<Customer*>::iterator itr = list.begin(); itr != list.end(); itr++){
    cout << (*itr)->getId() << " " << (*itr)->getName() << " Points: " << (*itr)->getPoints() << " Total Cost: " << (*itr)->getCost() << "$ ";
    if ((*itr)->getPurchSize()>0){
      for (int i = 0; i < (*itr)->getPurchSize(); i++){
        cout<<"Purchase Id: " << (*itr)->getPurchases().get(i)->getId() << " Quantity: " << (*itr)->getPurchases().get(i)->getUnits() << endl;
      }
    } else {
      cout<<" Purchases Id: (none) " <<" Quantity: (none) "<<endl;
    }
  }
}

/*
void UI::printStr(OrderArray &arr)
{
  cout << "ORDERS:" << endl << endl;

}*/

void UI::printError(string err)
{
  cout << endl << err << " -- press enter to continue...";
  cin.get();
}

void UI::printUsageError()
{
  cout << endl << "Usage:  cushop OPTION" << endl << endl;
  cout <<         "        where OPTION is either: " << endl;
  cout <<         "              -a  Admin menu"        << endl;
  cout <<         "              -c  Cashier menu"      << endl << endl;
}

void UI::promptForInt(string prompt, int& num)
{
  cout << prompt << ": ";
  num = readInt();
}

void UI::promptForStr(string prompt, string& str)
{
  cout << prompt << ": ";
  getline(cin, str);
}

void UI::promptForFloat(string prompt, float& num)
{
  string str;

  cout << prompt << ": ";
  getline(cin, str);

  stringstream ss(str);
  ss >> num;
}

int UI::readInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

void UI::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}
