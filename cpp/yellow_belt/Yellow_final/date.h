#pragma once
#include <iostream>

using namespace std;

class Date{
public:
    Date();
    Date(int year, int month, int day);
    int year_;
    int month_;
    int day_;
};

Date ParseDate(istream& is);

ostream& operator << (ostream& stream, const Date& date);

bool operator < (const Date& lhs, const Date& rhs);
bool operator > (const Date& lhs, const Date& rhs);
bool operator == (const Date& lhs, const Date& rhs);
