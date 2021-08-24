#include <deque>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
void Swap(T* first, T* second){
  auto temp = *first;
  *first = *second;
  *second = temp;
}

template <typename T>
void ReversedCopy(T* source, size_t count, T* destination){  
  size_t index = 0;
  while (index != count){
    destination[index] = *(source - index);
    ++index;
  }
  
}
int main() {
  const size_t count = 7;

  int* source = new int[count];
  int* dest = new int[count];

  for (size_t i = 0; i < count; ++i) {
      source[i] = i + 1;
  }

  ReversedCopy(source, count, dest);
  cout << dest[0] << endl;
  cout << dest[1] << endl;

    return 0;
}