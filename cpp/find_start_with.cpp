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


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
   RandomIt range_begin, RandomIt range_end,
   char prefix){

     string str = "";
     str = prefix;

     auto it = equal_range(range_begin, range_end, str,
     [prefix](const string& lhs, const string& rhs){
       return lhs[0] < rhs[0];
     });     
   
     return it;
}

//[&prefix](const string& lhs, const string& rhs) {
  //  return lhs.substr(0, prefix.size()) < rhs.substr(0, prefix.size()); }

int main() {
  const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};
  string prefix = "m";
  auto it = equal_range(begin(sorted_strings), end(sorted_strings),      
      prefix, 
      [&prefix] (const string& lhs, const string& rhs){
        return lhs.substr(0,prefix.size()) < rhs.substr(0, prefix.size());      });
  
  cout << *it.first << ' ' << *it.second << endl;

 const auto m_result =
     FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
 for (auto it = m_result.first; it != m_result.second; ++it) {
     cout << *it << " ";
 }

return 0;
}


