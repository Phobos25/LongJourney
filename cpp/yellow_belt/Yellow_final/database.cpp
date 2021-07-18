#include "database.h"

void Database::Add (const Date& date, const string& event){
//add
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
  auto it = db_.lower_bound(date);

  return "Last";
}
