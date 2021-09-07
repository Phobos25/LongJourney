#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  list <int> numbers = {1, 2, 3, 4, 5, 6};
  list <int> zero;
  auto it = zero.end();
  zero.insert(it,0);
  zero.insert(it,1);
  zero.insert(it,2);
  for (auto i:zero){
    cout << i << ' ';
  }
  cout << '\n';
  return 0;
}