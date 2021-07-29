#include "node.h"

bool EmptyNode :: Evaluate(const Date& date, const string& event){
    return true;
}

DateComparisonNode::DateComparisonNode(const Comparison& cmp, 
        const Date& date)
        : cmp_(cmp)
        , date_(date)
        {}

bool DateComparisonNode :: Evaluate(const Date& date, const string& event){
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

EventComparisonNode::EventComparisonNode(
        const Comparison& cmp, 
        const string& value)
        : cmp_(cmp)
        , value_(value)
        {}

bool EventComparisonNode :: Evaluate(const Date& date, const string& event){
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

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& op, 
        const shared_ptr<Node> ptr1,
        const shared_ptr<Node> ptr2)
        :op_(op)
        ,ptr1_(ptr1)
        ,ptr2_(ptr2)
        {}

bool LogicalOperationNode :: Evaluate(const Date& date, const string& event){
    if (op_ == LogicalOperation::And){
        return ptr1_ ->Evaluate(date, event) && ptr2_->Evaluate(date,event);
    }
    if (op_ == LogicalOperation::Or){
        return ptr1_ ->Evaluate(date, event) || ptr2_->Evaluate(date,event);
    }
	return false;
}
