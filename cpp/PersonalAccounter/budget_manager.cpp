#include "budget_manager.h"

using namespace std;

pair<string, string> SplitTwoStrict(string s, std::string delimiter) {
  const size_t pos = s.find(delimiter);
  if (pos == s.npos) {
    return {s, ""};
  } else {
    return {s.substr(0, pos), s.substr(pos + delimiter.length())};
  }
}

pair<string, string> SplitTwo(string s, string delimiter) {
  const auto [lhs, rhs] = SplitTwoStrict(s, delimiter);
  return {lhs, rhs};
}

std::string ReadToken(std::string& s, std::string delimiter = " ") {
  const auto [lhs, rhs] = SplitTwo(s, delimiter);
  s = rhs;
  return lhs;
}

int ConvertToInt(string str) {
  size_t pos;
  const int result = stoi(string(str), &pos);
  if (pos != str.length()) {
    stringstream error;
    error << "string " << str << " contains " << (str.length() - pos) << " trailing chars";
    throw invalid_argument(error.str());
  }
  return result;
}

time_t Date::AsTimestamp() const{
  tm t;
  t.tm_sec  = 0;
  t.tm_min  = 0;
  t.tm_hour = 0;
  t.tm_mday = day_;
  t.tm_mon  = month_ - 1;
  t.tm_year = year_ - 1900;
  t.tm_isdst = 0;
  return mktime(&t);
}
