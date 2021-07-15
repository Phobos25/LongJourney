#pragma once

#include "date.h"
#include "node.h"

#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Database{
public:
  void Add(const Date& date, const string& event);
  void Print(const ostream& os) const;
  
  template <typename T> 
  int RemoveIf(const T&  t );

  template <typename T>
  string FindIf(const T&  t );

  string Last(const Date& date);
};

template <typename T>
int Database::RemoveIf(const T& t){
  return 1;
}

template <typename T>
string Database::FindIf(const T& t){
  return "FindIf";
}