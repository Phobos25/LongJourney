#include <iostream>
#include <map>
#include <exception>

using namespace std;

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, Key k){
  if (m.count(k) == 0){
    throw runtime_error("runtime error");
  }
  return m[k];
}

int main(){
  map<int, string> m = {{0, "value"}};
  string& item = GetRefStrict(m, 0);
  item = "newvalue";
  cout << m[0] << endl; // выведет newvalue

  map<int, int> m1 = {{0, 1}};
  try {
    int& it = GetRefStrict(m1,0);
    it = 99;
  } catch (runtime_error){
    cout << "runtime_error" << endl;
  }
  cout << m1[0] << endl;

  return 0;
}
