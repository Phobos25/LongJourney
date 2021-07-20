#pragma once

#include "date.h"
#include "node.h"

#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

struct Entry{
  Entry(Date d, string s){
    date = d;
    str = s;
  }
  Entry() = default;
  Date date;
  string str;
};

struct Events{
  set <string> s;
  vector <string> v;
};

ostream& operator <<(ostream& stream, const Entry& entry);

class Database{
public:
  void Add(const Date& date, const string& event);
  void Print(ostream& os);

  string Last(const Date& date);

  template <typename T>
  int RemoveIf(const T&  t );

  template <typename T>
  vector<Entry> FindIf(const T&  t );

private:
  map <Date, Events> db_;
};

template <typename T>
int Database::RemoveIf(const T& predicate){ 
  int count = 0;
  map <Date, Events> new_db;
  for (auto& [key, values]:db_){
    for (auto& it: values.v){
      if (!predicate(key, it)){               
        new_db[key].s.insert(it);
        new_db[key].v.push_back(it);        
      }else{
        ++count;
      }
    }    
  }
  db_ = move(new_db);
  return count;
}

template <typename T>
vector<Entry> Database::FindIf(const T& predicate){
  vector<Entry> entries;
  for (auto& [key, values]:db_){
    for (auto& it:values.v){
      if (predicate(key, it)){
        Entry entry(key, it);
        entries.push_back(entry);
                
      }      
    }
  }
  return entries;
}
