#pragma once
#include <iostream>

using namespace std;

class Date{
public:
    Date() = delete;
    Date(int year, int month, int day);
    
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
private:
    int year_, month_, day_;
};

bool operator <  (const Date& lhs, const Date& rhs);
bool operator <= (const Date& lhs, const Date& rhs);
bool operator == (const Date& lhs, const Date& rhs);
bool operator != (const Date& lhs, const Date& rhs);
bool operator >  (const Date& lhs, const Date& rhs);
bool operator >= (const Date& lhs, const Date& rhs);

Date ParseDate(istream& is);

ostream& operator<<(ostream& stream, const Date& date);