#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix);


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix){
       auto lower = lower_bound(range_begin, range_end, prefix);
       auto upper = upper_bound(range_begin, range_end, prefix);
       return make_pair(lower, upper);
    }


int main() {
const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

const auto m_result =
    FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
for (auto it = m_result.first; it != m_result.second; ++it) {
    cout << *it << " ";
}
cout << endl;

return 0;
}