#include <set>
#include <iostream>

using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border){

        auto it = numbers.lower_bound(border);
        if (border < *it){
            int a = 2*border - *it;            
            if (numbers.count(a)){
                return numbers.find(a);
            }
        }
        if (*--numbers.end() < border){
            return numbers.end();
        }
        
        return it;
    }


// set<int>::const_iterator —
// тип итераторов для константного множес

int main() {
  set<int> numbers = {1, 4, 6};  
//   *FindNearestElement(numbers, 0);
//   *FindNearestElement(numbers, 3); 
//   *FindNearestElement(numbers, 5); 
//   *FindNearestElement(numbers, 6); 
//   *FindNearestElement(numbers, 100);

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