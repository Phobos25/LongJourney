#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  list <int> numbers = {1, 2, 3, 4, 5, 6};
  list <int> zero;
  vector<list <int>::iterator> v;
  auto it = zero.end();
  zero.insert(it,0);
  zero.insert(it,1);
  zero.insert(it,2);
  zero.insert(it,3);
  zero.insert(it,4);
  zero.insert(it,5);
  for (auto i:zero){
    cout << i << ' ';
  }
  cout << '\n';  
  
  auto it2 = zero.begin();
  v.push_back(it2++);
  v.push_back(it2++);
  v.push_back(it2++);
  for (auto j:v){
    zero.erase(j);
  } 

  for (auto i:zero){
    cout << i << ' ';
  }
  cout << '\n';
  return 0;
}