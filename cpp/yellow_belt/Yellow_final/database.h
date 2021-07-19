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

class Database{
public:
  void Add(const Date& date, const string& event);
  void Print(ostream& os);

  string Last(const Date& date);

  template <typename T>
  int RemoveIf(const T&  t );

  template <typename T>
  Entry FindIf(const T&  t );

private:
  map <Date, Events> db_;
};

template <typename T>
int Database::RemoveIf(const T& predicate){ 
  int count = 0;
  for (auto& [key, values]:db_){
    for (auto& it: values.v){
      if (predicate(key, it)){
        db_[key].v.erase(it);
        
        ++count;
      }
    }
    if (values.v.size() == 0){
      key = db_.erase(key);
    }
  }
  return count;
}

template <typename T>
Entry Database::FindIf(const T& predicate){
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
