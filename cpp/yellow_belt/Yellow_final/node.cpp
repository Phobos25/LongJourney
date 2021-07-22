#include "node.h"

bool EmptyNode :: Evaluate(const Date& date, const string& event){
  return true;
}

bool DateComparisonNode :: Evaluate(const Date& date,
                              const string& event){
  if (cmp_ == Comparison::Equal){
    return date == date_;
  }
  if (cmp_ == Comparison::Greater){
    return date > date_;
  }
  if (cmp_ == Comparison::GreaterOrEqual){
    return date >= date_;
  }
  if (cmp_ == Comparison::Less){
    return date < date_;
  }
  if (cmp_ == Comparison::LessOrEqual){
    return date <= date_;
  }else{
    return date != date_;
  }
}

bool EventComparisonNode :: Evaluate(
                        const Date& date,
                        const string& event){

  if (cmp_ == Comparison::Equal){
    return event == value_;
  }
  if (cmp_ == Comparison::Greater){
    return event > value_;
  }
  if (cmp_ == Comparison::GreaterOrEqual){
    return event >= value_;
  }
  if (cmp_ == Comparison::Less){
    return event < value_;
  }
  if (cmp_ == Comparison::LessOrEqual){
    return event <= value_;
  }
  else{
    return event != value_;
  }
}

bool LogicalOperationNode :: Evaluate(const Date& date, const string& event){
  if (op_ == LogicalOperation::And){
    return ptr1_->Evaluate(date, event) && ptr2_->Evaluate(date, event);
  }else {
    return ptr1_->Evaluate(date, event) || ptr2_->Evaluate(date, event);
  }
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
