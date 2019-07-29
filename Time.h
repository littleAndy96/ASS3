#ifndef TIMT_H_
#define TIMT_H_

#include <string>
using namespace std;


class Time {

public:

Time(); // constructor

void setTime( int, int, int ); // set hour, minute, second
void printTime() const; // print time format h:m:s
//void setTimeAP(int,int,int,string); // sets hour, minute, second and am or pm
//void printTimeAP(); // print time format h:m:s:am/pm

private:

int hour; // 0 - 23 (24-hour clock format)
int minute; // 0 - 59
int second; // 0 - 59
};

#endif /* TIMT_H_ */
