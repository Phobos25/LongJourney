#include "date.h"
#include <sstream>
#include <iomanip>

Date::Date(int year, int month, int day)
          : year_(year)
          , month_(month)
          , day_ (day)
{}

int Date::GetYear() const{return year_;}

int Date::GetMonth() const{return month_;}

int Date::GetDay() const{return day_;}

bool operator < (const Date& lhs, const Date& rhs){
  if (lhs.GetYear() == rhs.GetYear()){
    if (lhs.GetMonth() == rhs.GetMonth()){
      return lhs.GetDay() < rhs.GetDay();
    }
    return lhs.GetMonth() < rhs.GetMonth();
  }
  return lhs.GetYear() < rhs.GetYear();
}

bool operator <= (const Date& lhs, const Date& rhs){
  if (lhs.GetYear() == rhs.GetYear()){
    if (lhs.GetMonth() == rhs.GetMonth()){
      return lhs.GetDay() <= rhs.GetDay();
    }
    return lhs.GetMonth() <= rhs.GetMonth();
  }
  return lhs.GetYear() <= rhs.GetYear();
}

bool operator > (const Date& lhs, const Date& rhs){
  if (lhs.GetYear() == rhs.GetYear()){
    if (lhs.GetMonth() == rhs.GetMonth()){
      return lhs.GetDay() > rhs.GetDay();
    }
    return lhs.GetMonth() > rhs.GetMonth();
  }
  return lhs.GetYear() > rhs.GetYear();
}

bool operator >= (const Date& lhs, const Date& rhs){
  if (lhs.GetYear() == rhs.GetYear()){
    if (lhs.GetMonth() == rhs.GetMonth()){
      return lhs.GetDay() >= rhs.GetDay();
    }
    return lhs.GetMonth() >= rhs.GetMonth();
  }
  return lhs.GetYear() >= rhs.GetYear();
}

bool operator == (const Date& lhs, const Date& rhs){
  return lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay();
}

bool operator != (const Date& lhs, const Date& rhs){
  return lhs.GetYear() != rhs.GetYear() || lhs.GetMonth() != rhs.GetMonth() || lhs.GetDay() != rhs.GetDay();
}

Date ParseDate(istream& is){
  int year, month, day;
  is >> year;
  is.ignore(1);
  is >> month;
  is.ignore(1);
  is >> day;
  Date date = Date(year, month, day);
  return date;
}

ostream& operator<<(ostream& stream, const Date& date){
    stream << setfill('0');
    stream << setw(4) << date.GetYear() << '-'
           << setw(2) << date.GetMonth()<< '-'
           << setw(2) << date.GetDay();
    return stream;
}