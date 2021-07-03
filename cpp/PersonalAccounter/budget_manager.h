#pragma once
#include <string>
#include <sstream>
#include <algorithm>

std::pair<std::string, std::string> SplitTwoStrict(std::string s, std::string delimiter);

std::pair<std::string, std::string> SplitTwo(
    std::string s, std::string delimiter);

int ConvertToInt(std::string str);

std::string ReadToken(std::string& s, std::string delimiter);

class Date {
public:
  static Date FromString(std::string str){
    const int year = ConvertToInt(ReadToken(str, "-"));
    const int month = ConvertToInt(ReadToken(str, "-"));
    const int day = ConvertToInt(str);
    return {year, month, day};
  }

  // Weird legacy, can't wait for chrono::year_month_day
  time_t AsTimestamp() const;

private:
  int year_;
  int month_;
  int day_;

  Date(int year, int month, int day)
    : year_(year), month_(month), day_(day) {}
};
