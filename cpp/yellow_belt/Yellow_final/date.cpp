#include "date.h"
#include <sstream>
#include <iomanip>

Date::Date(){
  year_ = 0;
  month_ = 0;
  day_ = 0;
}

Date::Date(int year, int month, int day){
    year_ = year;
    month_ = month;
    day_ = day;
}

Date ParseDate(istream& is){
  int year, month, day;
  is >> year;
  is.ignore(1);
  is >> month;
  is.ignore(1);
  is >> day;
  return Date(year, month, day);
}

ostream& operator<<(ostream& stream, const Date& date){
    stream << setfill('0');
    stream << setw(4) << date.year_ << '-'
           << setw(2) << date.month_<< '-'
           << setw(2) << date.day_;
    return stream;
}

bool operator <(const Date& lhs, const Date& rhs){
  if (lhs.year_ == rhs.year_){
    if (lhs.month_ == rhs.month_){
      return lhs.day_ < rhs.day_;
    }else {lhs.month_ < rhs.month_;}
  }else {return lhs.year_ < rhs.year_; }
}

bool operator >(const Date& lhs, const Date& rhs){
  if (lhs.year_ == rhs.year_){
    if (lhs.month_ == rhs.month_){
      return lhs.day_ > rhs.day_;
    }else {lhs.month_ > rhs.month_;}
  }else {return lhs.year_ > rhs.year_; }
}

bool operator ==(const Date& lhs, const Date& rhs){
  if (lhs.year_ == rhs.year_){
    if (lhs.month_ == rhs.month_){
      return lhs.day_ == rhs.day_;
    }else {lhs.month_ == rhs.month_;}
  }else {lhs.year_ == rhs.year_;}
}

