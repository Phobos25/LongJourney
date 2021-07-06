#include <set>
#include <iostream>

using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border){

    if (numbers.empty()){
        return numbers.begin();
    }
    auto it = numbers.lower_bound(border);
    if ((it != numbers.begin()) & (it != numbers.end())){
      if (border - *prev(it) <=  *it - border){
        return prev(it);
      }
      else {
        return it;
      }
    }

    if (*prev(numbers.end()) < border){
        return prev(numbers.end());
    }

    if (*numbers.begin() > border){
        return numbers.begin();
    }
    return it;
    }

int main() {

  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;

  set<int> empty_set;

  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
