#include <iostream>
#include <map>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set <string> s; 
    for (const auto& [key, value]:m){
        s.insert(value);        
    }
    return s;
}