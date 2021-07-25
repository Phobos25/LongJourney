#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int num;
    cin >> num;
    vector <int> v(num);
    for (auto& i:v){
        cin >> i;
    }
    sort(v.begin(), v.end(),
            [] (int a, int b){
               return abs(a) < abs(b);
            });
    for (const auto& i:v){
        cout << i << ' ';
    }
    return 0;
}
