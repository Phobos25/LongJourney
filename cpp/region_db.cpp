#include <iostream>
#include <tuple>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};

auto GetRank(const Region& reg){
    return tie(reg.std_name, reg.parent_std_name, reg.names);
}

bool operator== (const Region& lhs, const Region& rhs){
  if (GetRank(lhs) == GetRank(rhs)){
    return lhs.population == rhs.population;
  }
  return false;
}

bool operator< (const Region& lhs, const Region& rhs){
  if (GetRank(lhs) == GetRank(rhs)){
    return lhs.population < rhs.population;
  }
  return GetRank(lhs) < GetRank(rhs);
}

bool operator> (const Region& lhs, const Region& rhs){
  if (GetRank(lhs) == GetRank(rhs)){
    return lhs.population > rhs.population;
  }
  return GetRank(lhs) > GetRank(rhs);
}

int FindMaxRepetitionCount(const vector<Region>& regions){
  map <Region, int> m;
  if (regions.empty()){
    return 0;
  }
  for (size_t i=0; i<regions.size(); ++i){
    m[regions[i]]++;
  }
  int count = 0;
  unsigned int max;  
  for (auto [first, second]:m){
    if (count == 0){
      max = second;
      ++count;
    }
    if (max < second){
      max = second;
    }
  }
  cout << max;
  return max;
}

int main(){
  vector <Region> regions;
  if (regions.empty()){
    cout << "empty" << endl;
  }

  // FindMaxRepetitionCount({
  //   {
  //     "Moscow",
  //     "Russia",
  //     {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
  //     89
  //   }, {
  //       "Russia",
  //       "Eurasia",
  //       {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
  //       89
  //   }, {
  //       "Moscow",
  //       "Russia",
  //       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
  //       89
  //   }, {
  //       "Moscow",
  //       "Russia",
  //       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
  //       89
  //   }, {
  //       "Russia",
  //       "Eurasia",
  //       {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
  //       89
  //   },
  // });

  return 0;
}


