#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iomanip>
#include <sstream>
#include <exception>

using namespace std;
// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public: 
  Date(int year, int month, int day){
    year_ = year;
    
    if (month < 1 || month > 12){                
      string error_msg = "Month value is invalid: " + to_string(month);
      throw runtime_error(error_msg);      
    } 
    
    month_ = month;

    if (day < 1 || day > 31){       
        string error_msg = "Day value is invalid: " + to_string(day);
        throw runtime_error(error_msg);        
      } 
    
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
void CheckNextAndIgnore(istringstream& stream);

Date ParseDate(istream& is);

class Database {
public:
  void AddEvent(const Date& date, const string& event){
    db_[date].insert(event);
  }

  bool DeleteEvent(const Date& date, const string& event){    
    if(db_.count(date) > 0 && db_[date].count(event) > 0){
      db_[date].erase(event);
      return true;
    } else {
      return false;
    }    
  }

  int DeleteDate(const Date& date){
    if (db_.count(date) == 0){
      return 0;
    }    
    int number_of_events = db_[date].size();
    db_.erase(date);
    return number_of_events;
  }

  set<string> Find(const Date& date) const{
    if (db_.count(date) > 0){
      return db_.at(date);
    }
    return {};
  }
  
  void Print() const{
    // private map <Date, Events> db_;    
    for (const auto& [key, value]:db_){
      for (const auto& v:value){
        cout << key << ' ' << v << "\n";
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

void CheckNextAndIgnore(istringstream& stream, const string& date){
  if (stream.peek() != '-'){    
    string error_msg = "Wrong date format: " + date;
    throw runtime_error(error_msg);
  }
  stream.ignore(1);
}

Date ParseDate(const string& date){
  istringstream is(date);
  int year, month, day;    
  
  is >> year;
  CheckNextAndIgnore(is, date); 
  is >> month;  
  CheckNextAndIgnore(is, date);  
  is >> day;

  if (!is.eof() || is.fail()){
    string error_msg = "Wrong date format: " + date;
    throw runtime_error(error_msg);      
  }       
  return Date(year, month, day);
}

void InputHandler(const string& command, Database& db){
    string com, strDate, event;
    stringstream ss(command);
    ss >> com;
    // Считайте команды с потока ввода и обработайте каждую
    if (com == "Add"){      
      ss >> strDate >> event;            
      Date date = ParseDate(strDate);
      db.AddEvent(date, event);
    } else if (com == "Print"){
      db.Print();
    } else if (com == "Del"){
      ss >> strDate >> event;      
      if (event.empty()){      
        Date date = ParseDate(strDate);        
        cout << "Deleted " << db.DeleteDate(date) << " events" << endl;      
      } else {      
        Date date = ParseDate(strDate);        
        if (db.DeleteEvent(date, event)){
          cout << "Deleted successfully" << endl;
        }else {
          cout << "Event not found" << endl;
        }                
      }  
    } else if (com == "Find"){
      ss >> strDate;    
      Date date = ParseDate(strDate);
      auto events = db.Find(date);         
      if (!events.empty()){
        for (auto& event:events){
          cout << event << "\n";
        }  
      }    
    } else if (com.empty()){
       } 
     else{
      throw runtime_error("Unknown command: " + com );       
    }
}

int main() {
  Database db;
  string command;
  while (getline(cin, command)) {
    try{
      InputHandler(command, db);
    } catch (exception& ex){
      cout << ex.what() << "\n";  
    }
  }
  return 0;
}