/* find_start_with.cpp
 * Created on: Jul 7, 2021
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix);


//template <typename RandomIt>
//pair<RandomIt, RandomIt> FindStartsWith(
//    RandomIt range_begin, RandomIt range_end,
//    char prefix){
//
//  if (range_begin == range_end){
//    return {range_begin, range_end};
//  }
//
//  vector<typename RandomIt::value_type> elements(range_begin, range_end);
//
//  auto it = lower_bound(range_begin, range_end, prefix,
//      [prefix] (const string& s){
//      return s[0] == prefix;
//  });
//
//  if (it == range_end){
//    return {range_begin, range_end};
//  }
//  return {{},{}};
//}

//[&prefix](const string& lhs, const string& rhs) { return lhs.substr(0, prefix.size()) < rhs.substr(0, prefix.size()); }

int main() {
  const vector<string> sorted_strings = {"akko","babylon","moscow", "murmansk", "vologda"};
  char prefix = 'm';
  auto it = equal_range(begin(sorted_strings), end(sorted_strings),
      &prefix);
  cout << *it.first << ' ' << *it.second << endl;
  cout << ++prefix << endl;
//  auto m_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
//  const auto m_result =
//      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
//  for (auto it = m_result.first; it != m_result.second; ++it) {
//      cout << *it << " ";
//  }
//  cout << endl;

return 0;
}


