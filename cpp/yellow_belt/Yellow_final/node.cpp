#include "node.h"

bool EmptyNode :: Evaluate(const Date& date, const string& event){
    return 0;
}

bool DateComparisonNode :: Evaluate(const Date& date, const string& event){
    return 0;
}

DateComparisonNode::DateComparisonNode(
                    const Comparison& cmp,
                    const Date& date){
  cmp_ = cmp;
  date_ = date;
}

EventComparisonNode::EventComparisonNode(
                    const Comparison& cmp,
                    const string& value){
  cmp_ = cmp;
  value_ = value;
}

bool EventComparisonNode :: Evaluate(const Date& date, const string& event){
    return 0;
}

bool LogicalOperationNode :: Evaluate(const Date& date, const string& event){
    return 0;
}
