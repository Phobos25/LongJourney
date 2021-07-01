#pragma once
#include <iostream>
#include "budget_manager.h"

bool operator<(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);

std::istream& operator>>(std::istream& stream, Date& date);