#include <iostream>
#include <tuple>
#include <map>
#include <string>
#include <vector>
#include <utility>

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

bool operator==(const Region& lhs, const Region&rhs){
  if (GetRank(lhs) == GetRank(rhs)){
    return lhs.population == rhs.population;
  }
  return false;
}

int FindMaxRepetitionCount(const vector<Region>& regions){
  map <Region, int> m={{regions[0], 1}};
}

int main(){
  cout << FindMaxRepetitionCount({
    {
      "Moscow",
      "Russia",
      {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
      89
    }, {
        "Russia",
        "Eurasia",
        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
        89
    }, {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89
    }, {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89
    }, {
        "Russia",
        "Eurasia",
        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
        89
    },
  }) << endl;

  return 0;
}


