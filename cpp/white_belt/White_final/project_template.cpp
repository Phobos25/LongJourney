#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;
// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
  Date(){
    year_ = 0;
    month_ = 0;
    day_ = 0;
  }
  Date(int year, int month, int day){
    year_ = year;
    month_ = month;
    day_ = day;
  }
  int GetYear() const{
    return year_;
  }
  int GetMonth() const{
    return month_;
  }
  int GetDay() const{
    return day_;
  }
private:
  int year_;
  int month_;
  int day_;
};

bool operator<(const Date& lhs, const Date& rhs);

Date ParseDate(istream& is);

class Database {
public:
  void AddEvent(const Date& date, const string& event){
    db_[date].push_back(event);
  }

  bool DeleteEvent(const Date& date, const string& event){
    if (db_[date].empty()){
      return false; // тут наверное должен искать event
    }else {
      db_[date].erase(remove(db_[date].begin(), 
                            db_[date].end(),
                            event), db_[date].end());
      return true;
    }
  }

  int  DeleteDate(const Date& date){
    int number_of_events = db_[date].size();
    db_[date].erase(db_[date].begin(), db_[date].end());
    return number_of_events;
  }

  /* ??? */ Find(const Date& date) const;
  
  void Print() const;

private:
  map<Date, vector<string>> db_;
};

bool operator <(const Date& lhs, const Date& rhs){
  if (lhs.GetYear() == rhs.GetYear()){
    if (lhs.GetMonth() == rhs.GetMonth()){
      return lhs.GetDay() < rhs.GetDay();
    }else {return lhs.GetMonth() < rhs.GetMonth();}
  }else {return lhs.GetYear() < rhs.GetYear(); }
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

int main() {
  Database db;
    
  string command;
  while (getline(cin, command)) {
    // Считайте команды с потока ввода и обработайте каждую
  }

  return 0;
}