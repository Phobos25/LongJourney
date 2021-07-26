#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iomanip>
#include <sstream>

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
ostream& operator<<(ostream& stream, const Date& date);
bool operator==(const Date& lhs, const Date& rhs);

Date ParseDate(istream& is);

class Database {
public:
  void AddEvent(const Date& date, const string& event){
    db_[date].insert(event);
  }

  bool DeleteEvent(const Date& date, const string& event){    
    if(db_[date].count(event) == 0){
      return false; //такого ивента нте
    } else {
      db_[date].erase(event);
      return true;
    }    
  }

  int DeleteDate(const Date& date){
    int number_of_events = db_[date].size();
    db_[date].erase(db_[date].begin(), db_[date].end());
    return number_of_events;
  }

  void Find(const Date& date) const{
    for (const auto& [key, value]: db_){
      if (key == date){
        for (const auto& v: value){
          cout << v << "\n";
        }
      }      
    }
  }
  
  void Print() const{
    // private map <Date, Events> db_;
    for (const auto& it:db_){
      for (const auto& v:it.second){
        cout << it.first << ' ' << v << "\n";
      }
  }
  }

private:
  map<Date, set<string>> db_;
};

bool operator <(const Date& lhs, const Date& rhs){
  if (lhs.GetYear() == rhs.GetYear()){
    if (lhs.GetMonth() == rhs.GetMonth()){
      return lhs.GetDay() < rhs.GetDay();
    }else {return lhs.GetMonth() < rhs.GetMonth();}
  }else {return lhs.GetYear() < rhs.GetYear(); }
}

ostream& operator<<(ostream& stream, const Date& date){
    stream << setfill('0');
    stream << setw(4) << date.GetYear() << '-'
           << setw(2) << date.GetMonth()<< '-'
           << setw(2) << date.GetDay();
    return stream;
}

bool operator==(const Date& lhs, const Date& rhs)
{
	return lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay();
}

Date ParseDate(string& date){
  istringstream is(date);
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
    string com, date, event;
    stringstream ss(command);
    ss >> com;
    // Считайте команды с потока ввода и обработайте каждую
    if (com == "Add"){      
      ss >> date >> event;
      db.AddEvent(ParseDate(date), event);
    } else if (com == "Print"){
      db.Print();
    } else if (com == "Del"){
      ss >> date >> event;
      if (event.empty()){
        int num = db.DeleteDate(ParseDate(date));
        cout << "Deleted " << num << " events" << endl;
      } else {
        const bool b = db.DeleteEvent(ParseDate(date), event);
        if (b){
          cout << "Deleted successfully" << endl;
        }else {
          cout << "Event not found" << endl;
        }
      }  
    } else if (com == "Find"){
      ss >> date;
      db.Find(ParseDate(date));
    } else {
      cout << "Unknown command: "<< com << endl;
    }

  }

  return 0;
}