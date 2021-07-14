#pragma once
#include "date.h"

using namespace std;

class Node{
public:
  virtual bool Evaluate(const Date& date, const std::string& event) = 0;
};

class EmptyNode: public Node{
public:
  bool Evaluate(const Date& date, const string& event) override;
};

class DateComparisonNode: public Node{
  bool Evaluate(const Date& date, const string& event) override;
};

class EventComparisonNode: public Node{
  bool Evaluate(const Date& date, const string& event) override;
};

class LogicalOperatorNode: public Node{
  bool Evaluate(const Date& date, const string& event) override;
};
