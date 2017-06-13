#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

Date::Date(int d, int m, int y)
{
  setDate(d, m, y);
}

Date::~Date(){}

void Date::operator+=(int numDays){
  this->day += numDays;
  while (this->day > this->lastDayInMonth()){
    this->day = this->day - this->lastDayInMonth();
    this->month++;
  }
  while (this->month > 12){
    this->month = this->month-12;
    this->year++;
  }
}

string Date::toString(){
  stringstream str;
  str << day << "/" << month << "/" << year << endl;
  return str.str();

}

Date Date::operator+(const int numDays){
  Date retDate(this->day, this->month, this->year);
  retDate+=numDays;
  return retDate;
}

bool Date::operator<(Date& other){
  if (this->year < other.year){return true;}
  if (this->month < other.month){return true;}
  if (this->day < other.day){return true;}
  return false;
}

/*
void Date::operator=(Date& other){
  this->day = other.day;
  this->month = other.day;
  this->year = other.year;
}*/

bool Date::operator==(Date& other){
  if (this->year != other.year){return false;}
  if (this->month != other.month){return false;}
  if (this->day != other.day){return false;}
  return true;
}

bool Date::operator>(Date& other){
  if (*this==other){return false;}
  if (!(*this<other)){return true;}
  else {return false;}
}

void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

void Date::printShort() const
{
  cout<<setfill('0')<<setw(2)<<day<<"/"
      <<setfill('0')<<setw(2)<<month<<"/"
      <<setfill('0')<<setw(4)<<year<<endl;
}

int Date::getDay(){
  return day;
}

int Date::getMonth(){
  return month;
}

int Date::getYear(){
  return year;
}

void Date::printLong() const
{
  cout<<"Const printing: " << getMonthStr()<<" "<<day<<", "<<year<<endl;
}

void Date::printLong()
{
  cout<<"Non-const printing: " << getMonthStr()<<" "<<day<<", "<<year<<endl;
}

int Date::lastDayInMonth()
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

string Date::getMonthStr() const
{
  string monthStrings[] = {
    "January", "Februrary", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}
