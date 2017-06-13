#ifndef DATE_H
#define DATE_H
#include <string>
#include <sstream>
using namespace std;

class Date
{
  public:
    Date(int=0, int=0, int=0);
    ~Date();
    void setDate(int, int, int);
    void printShort() const;
    void printLong() const;
    void printLong();
    void operator+=(int);
    Date operator+(const int);
    bool operator<(Date&);
    bool operator>(Date&);
    bool operator==(Date&);
    int  getDay();
    int  getMonth();
    int  getYear();
    string toString();

  private:
    int day;
    int month;
    int year;
    int  lastDayInMonth();
    bool leapYear();
    string getMonthStr() const;
};

#endif
