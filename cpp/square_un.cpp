#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;

template <typename T>
T Sqr(T x){
  return x*x;
}

template <typename T>
vector<T> operator* (const vector<T>& lhs, const vector<T>& rhs){
  vector<T> result;
  for (auto i=0; i<lhs.size(); ++i){
    result.push_back(lhs[i] * rhs[i]);
  }
  return result;
}

template <typename First, typename Second>
pair<First, Second> operator* (const pair<First, Second>& lhs, const pair<First, Second>& rhs){
  First f = lhs.first * rhs.first;
  Second s= lhs.second * rhs.second;
  return make_pair(f, s);
}

template <typename Key, typename Value>
map<Key, Value> operator* (map<Key, Value>& lhs, map<Key, Value>& rhs){
  map<Key, Value> result;
  for (const auto [key, value]:lhs){
    result[key] = value*value;
  }
  return result;
}


int main(){
  vector<int> v = {1, 2, 3};
  cout << "vector:";
  for (int x : Sqr(v)) {
    cout << ' ' << x;
  }
  cout << endl;

  map<int, pair<int, int>> map_of_pairs = {
    {4, {2, 2}},
    {7, {4, 3}}
  };
  cout << "map of pairs:" << endl;
  for (const auto& x : Sqr(map_of_pairs)) {
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
  }
  return 0;
}
