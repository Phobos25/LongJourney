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
  while (size != 0) {    
    *(first++) = *(beg + cur_pos);    
    --size;
    if (size == 0) {
      break;
    }
    cur_pos = (cur_pos + step_size - 1) % size;
  }
}

int main() {
  vector<int> v = {1,2,3,4,5};
  MakeJosephusPermutation(begin(v), end(v), 2);
  for (auto i:v){
    cout << i << ' ';
  }
  cout << endl;
  return 0;

}
