#pragma once

using namespace std;

class Node{
public:
  int Evaluate(const Date& date, const string& event);
};

class EmptyNode: public Node{

};

class DateComparisonNode: public Node{

};

class EventComparisonNode: public Node{

};

class LogicalOperatorNode: public Node{

};
