#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int num;
    cin >> num;
    vector<string> v(num);

    for (auto& i: v){
        cin >> i;
    }
    
    sort (v.begin(), v.end(), 
         [](string lhs, string rhs){
             for (int i=0; i<lhs.size(); ++i){
                lhs[i] = tolower(lhs[i]);
            }
            for (int i=0; i<lhs.size(); ++i){
                rhs[i] = tolower(rhs[i]);
            }
            return lhs < rhs; 
         });
    
    for (const auto& i:v){
        cout << i << ' ';
    }
    return 0;
}