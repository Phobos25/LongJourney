#include "simple_vector.h"
#include "test_runner.h"

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
void Print(const SimpleVector<T>& v){
  for (auto i = v.begin(); i!= v.end(); ++i){
    cout << i << ':' << *i << endl;
  }
}

int main2() {      
   SimpleVector<int> sv;
   sv.PushBack(1);
   sv.PushBack(2);
   cout << "Size: " << sv.Size() << endl;
   cout << "Capacity: " << sv.Capacity() << endl;
   Print(sv);

   sv.PushBack(3);
   sv.PushBack(4);
   cout << "Size: " << sv.Size() << endl;
   cout << "Capacity: " << sv.Capacity() << endl;
   Print(sv);
}