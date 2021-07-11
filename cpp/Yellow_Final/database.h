#pragma once

#include <string>
#include <iostream>
#include <memory>

class Database{
public:
  void Add(const std::string& date, const std::string& event);
  void Print(std::ostream& os);
  int RemoveIf(std::shared_ptr<Node>&  predicate );
  std::string FindIf(std::shared_ptr<Node>&  predicate );
};
