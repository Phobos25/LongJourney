#include <iostream>
#include <list>
#include <set>

using namespace std;

int main() {
  list<int> athletes;
  set<int> numbers;
  int query_count;
  int first, second;
  cin >> query_count;
  bool first_run = true;  
  for (int i= 0; i< query_count; ++i){
    cin >> first >> second;    
    if (second == 0 || numbers.count(second) == 0){
        athletes.push_back(first);
        numbers.insert(first);
    } else {        
        auto it = athletes.begin();
        while (it != athletes.end()){
        if (*it == second){
          athletes.insert(it, first);  
          numbers.insert(first);
          break;
        }
        ++it;  
        }    
    }        
  }

  for (auto it: athletes){
    cout << it << endl;
  }
  return 0;
}