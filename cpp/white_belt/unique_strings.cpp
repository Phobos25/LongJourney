#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int n;
    set<string> s;

    cin >> n;
    for (int i=0; i < n; ++i){
        string k;
        cin >> k;
        s.insert(k);
    }

    cout << s.size();
    return 0;
}