#pragma once
#ifndef __CALENDAR__
#define __CALENDAR__

#include <iostream>

using namespace std;

enum weekday {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSTDAY,
    FRIDAY,
    SATURDAY
};

weekday operator+(weekday day, int days);
ostream& operator<< (ostream& strm, weekday day);

#endif // !__CALENDAR__
