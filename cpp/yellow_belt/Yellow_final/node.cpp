#include "node.h"

bool EmptyNode :: Evaluate(const Date& date, const string& event){
  return true;
}

bool DateComparisonNode :: Evaluate(const Date& date, const string& event){
  return true;
}

bool EventComparisonNode :: Evaluate(
                        const Date& date,
                        const string& event){

  if (cmp_ == Comparison::Equal){
    return value_ == event;
  }
  if (cmp_ == Comparison::Greater){
    return value_ > event;
  }
  if (cmp_ == Comparison::GreaterOrEqual){
    return value_ >= event;
  }
  if (cmp_ == Comparison::Less){
    return value_ < event;
  }
  if (cmp_ == Comparison::LessOrEqual){
    return value_ <= event;
  }
  else{
    return value_ != event;
  }
}

bool LogicalOperationNode :: Evaluate(const Date& date, const string& event){
  return true;
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
