#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(){
    map<int, string> m;
    vector<int> v = {1,2,3,4};
    m[0] = "zero";
    m[1] = "one";

    for (auto& it: m){
        cout << it.second << endl;
        break;
    }
    
    return 0;
}