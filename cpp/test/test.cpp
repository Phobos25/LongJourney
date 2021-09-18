#include <cstdint>
#include <iterator>
#include <numeric>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

template <typename RandomIt>
void MakeJosephusPermutation(RandomIt first, RandomIt last, uint32_t step_size) {  
  auto beg = first;
  size_t cur_pos = 0;
  size_t size = last - first;  
  while (cur_pos != size){    
    if ((*first % step_size == 0) && (*first != 0)){
      auto it = first;
      // cout << *it << endl;
      while (next(it) != last){
        swap(*it, *(next(it)));
        ++it;
      }
    }
    ++cur_pos;      
    ++first;  
  }
  // надо проитерироваться по всему вектору, видимо циклом while, т.к. for не будет работать
  // внутри цикла нужен еще 1 цикл, чтобы методом swap перемещать значения элементом назад 
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
  // MakeJosephusPermutation2(begin(v), end(v), 2); 
  MakePermutation(begin(numbers), end(numbers), 3);  
  for (auto i:numbers){
    cout << i << ' ';
  }
  cout << endl;
  return 0;

}
