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
    return stream << std::setw(4) << std::setfill('0') << date.GetYear() << '-'
			   << std::setw(2) << std::setfill('0') << date.GetMonth() << '-'
			   << std::setw(2) << std::setfill('0') << date.GetDay();
}