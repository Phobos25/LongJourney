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

class Database{
public:
  void Add(const Date& date, const string& event);
  void Print(ostream& os);

  string Last(const Date& date);

  template <typename T>
  int RemoveIf(const T&  t );

  template <typename T>
  string FindIf(const T&  t );

private:
  map <Date, Events> db_;
};

template <typename T>
int Database::RemoveIf(const T& t){ 
  return 1;
}

template <typename T>
string Database::FindIf(const T& t){
  return "FindIf";
}
