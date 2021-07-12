#pragma once

#include "date.h"

#include <string>
#include <iostream>
#include <memory>

class Database{
public:
  void Add(const Date& date, const std::string& event);
  void Print(std::ostream& os);
  int RemoveIf(std::shared_ptr<Node>&  predicate );
  std::string FindIf(std::shared_ptr<Node>&  predicate );
};
