#include "profile.h"
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

class NumbersOnVector{
public:
  void Add(int x){
    data.push_back(x);
  }

  template <typename Predicate>
  void Remove(Predicate predicate){
    data.erase(
      remove_if(begin(data), end(data), predicate), 
            end(data));
  }
private:
  vector<int> data;
};

class NumbersOnList{
public:
  void Add(int x){
    data.push_back(x);
  }

  template <typename Predicate>
  void Remove(Predicate predicate){
    data.remove_if(predicate);
  }
private:
  list<int> data;
};

const int SIZE = 10'000;
const int REMOVAL_COUNT = 1000;

int main() {
  { LOG_DURATION("vector");
    NumbersOnVector numbers;
    for (int i =0; i< SIZE; ++i){
      numbers.Add(i) ;
    }
    for (int i=0; i < REMOVAL_COUNT; ++i){
      numbers.Remove([i](int x) {return x % REMOVAL_COUNT == i;});
    }
  }
  { LOG_DURATION("list");
    NumbersOnVector numbers;
    for (int i =0; i< SIZE; ++i){
      numbers.Add(i);
    }
    for (int i=0; i < REMOVAL_COUNT; ++i){
      numbers.Remove([i](int x) {return x % REMOVAL_COUNT == i;});
    }
  }
  return 0;
}