#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

struct test
{
    string name;
};

int main(){
    // time id room
    map<string, map<int, string>> m;
    m["one"][0] = "zero";
    m["two"][0] = "zero";

    for (auto& it: m){
        cout << it.first << endl;
    }
    return 0;
}