#include "Calendar.h"

weekday operator+(weekday day, int days) {
	return static_cast<weekday>((static_cast<int>(day) + days) % 7);
}

ostream& operator<< (ostream& strm, weekday day){

    switch (day) {
    case SUNDAY: 
        strm << "SUNDAY";       
        break;
    case MONDAY: 
        strm << "MONDAY";       
        break;
    case TUESDAY: 
        strm << "TUESDAY";      
        break;
    case WEDNESDAY: 
        strm << "WEDNESDAY";    
        break;
    case THURSTDAY: 
        strm << "THURSDAY";     
        break;
    case FRIDAY: 
        strm << "FRIDAY";       
        break;
    case SATURDAY: 
        strm << "SATURDAY";     
        break;
    default:  
        strm << "Somewhere inside the depths of time...";
    }

    return strm;
}