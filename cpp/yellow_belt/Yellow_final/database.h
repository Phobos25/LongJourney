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

struct Events{
  set <string> s;
  vector <string> v;
};

struct Entry{
  Date date;
  string str;
};

ostream& operator << (ostream& stream, const Entry& entry);

class Database{
public:
  void Add(const Date& date, const string& event);
  void Print(ostream& os);

  string Last(const Date& date);

  template <typename T>
  int RemoveIf(const T&  t );

  template <typename T>
  vector<Entry> FindIf(const T&  predicate );

private:
  map <Date, Events> db_;
};

template <typename T>
int Database::RemoveIf(const T& t){
  return 1;
}

template <typename T>
vector<Entry> Database::FindIf(const T& predicate){
  vector <Entry> entries;
  for (auto& [key, value]: db_){
    for (auto& it:value.v){
      if (predicate(key, it)){
        Entry entry;
        entry.date = key;
        entry.str = it;
        entries.push_back(entry);
      }
    }
  }
  return entries;
}
