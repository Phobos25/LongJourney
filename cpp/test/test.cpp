#include <cstdint>
#include <iterator>
#include <numeric>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

template <typename RandomIt>
void MakeJosephusPermutation(RandomIt first, RandomIt last, uint32_t step_size) {    
  size_t cur_pos = 0;  
  while (first != last){
    auto it = first + cur_pos;
    while (*it != *first){
      swap(*(prev(it)), *it);
      --it;
    }
    if ( next(first) == last){
      break;
    }
    cur_pos = (cur_pos + step_size - 1) % (prev(last) - first);    
    ++first;
  }
}

template <typename RandomIt>
void MakePermutation(RandomIt first, RandomIt last, uint32_t step_size) {
  vector<typename RandomIt::value_type> pool(first, last);  
  size_t cur_pos = 0;
  while (!pool.empty()) {
    *(first++) = pool[cur_pos];
    // cout << *(pool.begin() + cur_pos) << endl;
    pool.erase(pool.begin() + cur_pos);
    if (pool.empty()) {
      break;
    }
    cur_pos = (cur_pos + step_size - 1) % pool.size();
    // cout << cur_pos << endl;
  }
}


vector<int> MakeTestVector() {
  vector<int> numbers(10);
  iota(begin(numbers), end(numbers), 0);
  return numbers;
}

int main() {
  vector<int> v = {1,2,3,4,5};
  vector<int> numbers = MakeTestVector();
  vector<int> ethalon = MakeTestVector();
  // MakeJosephusPermutation(begin(v), end(v), 2); 
  MakeJosephusPermutation(begin(numbers), end(numbers), 3); 
  // MakePermutation(begin(v), end(v), 2);  
  cout << "after my permutation: ";
  for (auto i:numbers){
    cout << i << ' ';
  }
  cout << endl;
 
  return 0;
}
