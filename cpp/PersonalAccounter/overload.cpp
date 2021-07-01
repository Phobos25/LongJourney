#include "overload.h"

bool operator<(const Date& lhs, const Date& rhs){
    if (lhs.year == rhs.year){
        if (lhs.month == rhs.month){return lhs.day < rhs.day;}
        else {return lhs.month < rhs.month;}
    }else {
        return lhs.year < rhs.year;
        }
}

bool operator>(const Date& lhs, const Date& rhs) {
    if (lhs.year == rhs.year){
        if (lhs.month == rhs.month){return lhs.day > rhs.day;}
        else {return lhs.month > rhs.month;}
    }else {
        return lhs.year > rhs.year;
        }
}

bool operator==(const Date& lhs, const Date& rhs){
    if (lhs.year == rhs.year){
        if (lhs.month == rhs.month){
            return lhs.day == rhs.day;
        }
    }
    return false;
}

std::istream& operator>>(std::istream& stream, Date& date){    
    stream >> date.year; 
    stream.ignore(1);
    stream >> date.month;
    stream.ignore(1);
    stream >> date.day;
    return stream;    
}
