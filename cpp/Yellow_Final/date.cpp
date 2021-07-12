#include "Date.h"
#include <sstream>
#include <iomanip>

Date::Date(int year, int month, int day){
    year_ = year;
    month_ = month;
    day_ = day;
}

Date ParseDate(istream& is){
  stringstream stream;
  int year, month, day;
  stream >> year;
  stream.ignore(1);
  stream >> month;
  stream.ignore(1);
  stream >> day;
  Date date = Date(year, month, day);
  return date;
}

ostream& operator<<(ostream& stream, const Date& date){
    stream << setfill('0');
    stream << date.year_ << '-'
           << setw(2) << date.month_
           << setw(2) << date.day_;
}