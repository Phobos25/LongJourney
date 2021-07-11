#pragma once

using namespace std;

class Node{
public:
  virtual int Evaluate(Date& date, const string& event) = 0;
};

class EmptyNode: public Node{

};

class DateComparsionNode: public Node{

};

class EventComparisonNode: public Node{

};

class LogicalOperatorNode: public Node{

};
