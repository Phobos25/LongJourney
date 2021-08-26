#include "simple_vector.h"
#include "test_runner.h"

#include <iostream>

using namespace std;

template <typename T>
void Print(const SimpleVector<T>& v){
  for (auto i = v.begin(); i!= v.end(); ++i){
    cout << i << ':' << *i << endl;
  }
}

int main2() {   
   
    SimpleVector<string> five_strings(5);
    ASSERT_EQUAL(five_strings.Size(), 5u);
    cout << five_strings.Size() << endl;
    ASSERT(five_strings.Size() <= five_strings.Capacity());
    cout << five_strings.Size()<< " <= " << five_strings.Capacity() << endl;
    for (auto& item : five_strings) {
      ASSERT(item.empty());
      cout << "empty: " << item << endl;
    }
    five_strings[2] = "Hello";
    ASSERT_EQUAL(five_strings[2], "Hello");
    cout << five_strings[2] << endl;
}