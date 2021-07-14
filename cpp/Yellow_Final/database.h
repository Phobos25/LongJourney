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
  int RemoveIf(const bool&  predicate );
  string FindIf(const bool&  predicate );
  string Last(const Date& date);
};
