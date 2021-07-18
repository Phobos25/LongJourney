#include "database.h"


ostream& operator << (ostream& stream, const Entry& entry){
  stream << entry.date;
  stream << ' ';
  stream << entry.str;
  return stream;
}

void Database::Add (const Date& date, const string& event){
<<<<<<< HEAD
// private map <Date, Events> db_;
  if (db_[date].s.count(event) == 0){
    db_[date].s.insert(event);
    db_[date].v.push_back(event);
  }  
=======
//private  map <Date, Events> db_;
  if (db_[date].s.count(event) == 0){
    db_[date].s.insert(event);
    db_[date].v.push_back(event);
  }
>>>>>>> 9f5f08cff6ca1d716a3a4602a5f164975cf2b3f8
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
<<<<<<< HEAD
    stringstream stream; 
    stream << (*prev(it)).first;    
    stream << ' ';
    stream << (*prev(it)).second.v.back();
=======
    stringstream stream;
    stream << it -> first;
    stream << ' ';
    stream << it -> second.v.back();
>>>>>>> 9f5f08cff6ca1d716a3a4602a5f164975cf2b3f8
    return stream.str();
  }else {
    return "No entries";
  }
<<<<<<< HEAD
  
=======
>>>>>>> 9f5f08cff6ca1d716a3a4602a5f164975cf2b3f8
  return "Last";
}
