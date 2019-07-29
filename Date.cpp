#include <iostream>
#include "Date.h"

using namespace std;

// Constructor
Date::Date (int d, int m, int y)
{
day = d;
month = m;
year = y ;
}

// print date
void Date::printDate() const
{
cout << month << "/" << day << "/" << year << "\n";
}

// set date
void Date::setDate(int day,int month,int year){

    this->day = ( day >= 1 && day <= 31 ) ? day : 0;
    this->month = ( month >= 1 && month <= 12 ) ? month : 0;
    this->year = ( year >= 0 ) ? year : 0;
}

/* void Date::printMonth() const{
    char months[12] = ["January","February","March","April","May","June","July","August","September","October","November","December"];

    return months[month];

}

int Date::dateDifference(int date1,int date2) {

    int result1,result2,total,temp = 0;

    if (date1 < date2){
        date1 = temp;
        date1 = date2;
        date2 = temp;
    }

    result1 = date1->year*365 + date1->month*30 + date1->day;
    result2 = date2->year*365 + date2->month*30 + date2->day;

    total = result1 - result2;

    return total;
}*/