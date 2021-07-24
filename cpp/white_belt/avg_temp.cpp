#include <iostream>
#include <vector>

using namespace std;

int main(){
  unsigned int n;
  cin >> n;
  vector<int> temperature(n);
  for (int& t:temperature){
    cin >> t;
  }
  int64_t summa=0;
  for (auto t:temperature){
    summa += t;
  }
  summa /= n;
  vector<int> greater;
  for (size_t i=0; i<n; ++i){
    if (temperature[i] > summa){
      greater.push_back(i);
    }
  }
  cout << greater.size() << endl;
  for (auto i:greater){
    cout << i << ' ';
  }
  return 0;
}


