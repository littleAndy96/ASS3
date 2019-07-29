#include <iostream>

#include "Time.h"

using namespace std;

// Time constructor
Time::Time()
{
hour = 0;
minute = 0;
second = 0;
}

// set new Time value
void Time::setTime( int h, int m, int s )
{
hour = ( h >= 0 && h < 24 ) ? h : 0;
minute = ( m >= 0 && m < 60 ) ? m : 0;
second = ( s >= 0 && s < 60 ) ? s : 0;
}

// print Time
void Time::printTime() const
{
cout << hour << ":" << minute << ":" << second << "\n";
}

/* void Time::setTimeAP(int h, int m, int s, string t){
	hour = ( h >= 0 && h < 24 ) ? h : 0;
	minute = ( m >= 0 && m < 60 ) ? m : 0;
	second = ( s >= 0 && s < 60 ) ? s : 0;
	if (t == "PM" || t == "pm"){
		hour += 12;
	}
}

void Time::printTimeAP()
{
	string t;

	if(hour > 12){
		hour -= 12;
		t = 'PM';
		}
	else {
		t = 'AM';
	}

cout << hour << ":" << minute << ":" << second << t << endl;
}
*/