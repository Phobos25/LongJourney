#pragma once
#include "overload.h"
#include <map>

struct Date{
    int year;
    int month;
    int day;
};

class BudgetManager{
public: 

    void ComputeIncome(const Date& from, const Date& to);

    void Earn(const Date& from, const Date& to, const double& value);

private:
    std::map<Date, double> budget;
};
