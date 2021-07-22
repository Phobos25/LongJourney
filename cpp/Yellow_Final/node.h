#pragma once
#include "date.h"

#include <memory>
#include <string>
using namespace std;

enum class Comparison{
  Less,
  LessOrEqual,
  Greater,
  GreaterOrEqual,
  Equal,
  NotEqual,
};

enum class LogicalOperation{
  Or,
  And,
};

class Node{
public:
  virtual bool Evaluate(const Date& date, const std::string& event) = 0;
};

class EmptyNode: public Node{
public:
  EmptyNode() = default;

  bool Evaluate(const Date& date, const string& event) override;
};

class DateComparisonNode: public Node{
public:
  DateComparisonNode() = default;
  DateComparisonNode(const Comparison& cmp, const Date& date);

  bool Evaluate(const Date& date, const string& event) override;

private:
  Comparison cmp_;
  Date date_;
};

class EventComparisonNode: public Node{
public:
  EventComparisonNode() = default;
  EventComparisonNode(const Comparison& cmp, const string& value);

  bool Evaluate(const Date& date, const string& event) override;
private:
  Comparison cmp_;
  string value_;
};

class LogicalOperationNode: public Node{
public:
  LogicalOperationNode() = default;
  LogicalOperationNode(const LogicalOperation& op, 
        const shared_ptr<Node> ptr1,
        const shared_ptr<Node> ptr2);

  bool Evaluate(const Date& date, const string& event) override;

private:
  const LogicalOperation op_;
  shared_ptr<Node> ptr1_, ptr2_;
};
