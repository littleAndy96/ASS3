#ifndef DATE_H_
#define DATE_H_

class Date {

public:

Date(int=1, int=1, int=2000); // sets day, month, year
void setDate(int,int,int); // new function to set day,month,year
void printDate() const; // print date to the screen
//void printMonth() const; // print month in letters
//int dateDifference(int,int); // returns the number of days between two dates

private:

int day;
int month;
int year;
};

#endif /* DATE_H_ */
