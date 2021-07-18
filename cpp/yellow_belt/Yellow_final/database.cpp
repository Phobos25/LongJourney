#include "database.h"

void Database::Add (const Date& date, const string& event){
//private  map <Date, Events> db_;
  if (db_[date].s.count(event) == 0){
    db_[date].s.insert(event);
    db_[date].v.push_back(event);
  }
}

void Database::Print(ostream& os){
// private map <Date, Events> db_;
  for (const auto& it:db_){
    for (const auto& v:it.second.v){
      os << it.first << ' ' << v << "\n";
    }
  }
}

string Database::Last(const Date& date){
  auto it = db_.upper_bound(date);
  if (it != db_.begin()){
    stringstream stream;
    stream << it -> first;
    stream << ' ';
    stream << it -> second.v.back();
    return stream.str();
  }else {
    return "No entries";
  }
  return "Last";
}
