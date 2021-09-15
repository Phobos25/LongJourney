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
  // надо проитерироваться по всему вектору, видимо циклом while, т.к. for не будет работать
  // внутри цикла нужен еще 1 цикл, чтобы методом swap перемещать значения элементом назад
  
}

template <typename RandomIt>
void MakeJosephusPermutation2(RandomIt first, RandomIt last, uint32_t step_size) {
  vector<typename RandomIt::value_type> pool(first, last);  
  size_t cur_pos = 0;
  while (!pool.empty()) {
    *(first++) = pool[cur_pos];
    pool.erase(pool.begin() + cur_pos);
    if (pool.empty()) {
      break;
    }
    cur_pos = (cur_pos + step_size - 1) % pool.size();
  }
}

int main() {
  vector<int> v = {1,2,3,4,5};
  // MakeJosephusPermutation2(begin(v), end(v), 2); 
  MakeJosephusPermutation(begin(v), end(v), 2);  
  for (auto i:v){
    cout << i << ' ';
  }
  cout << endl;
  return 0;

}
