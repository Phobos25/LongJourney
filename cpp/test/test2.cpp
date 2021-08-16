#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector <int> v = {10, 8, 6, 6, 6, 6, 6, 6, 5, 4, 4,4,4,4,4, 2};
  int key;
  for (auto it:v){
      cout << it << ' ';
  }
  cout << endl;
  cout << "enter a value for search" << endl;
  cin >> key;  
//   sort(v.begin(), v.end());

  bool flag = false;  
  int l = 0;
  int r = v.size()-1;
  int mid;
  cout << v.size() << endl;
  while ((l <= r) && (flag != true)) {
    mid = (l+r)/2;
    if (v[mid] < key) { 
        if (v[mid-1] == key){
            flag = true;
            mid--;
        } else {
            r = mid-1;
        }
    }
    if (v[mid] == key) {
        l = mid + 1;
    } else {
        l++;
    }   
  }

  if (flag){
        cout << "the element: "  << key 
             << " was found at: "<< mid << endl;
    } else {
        cout << "the element couldn't be found" << endl;
    }
  return 0;
}