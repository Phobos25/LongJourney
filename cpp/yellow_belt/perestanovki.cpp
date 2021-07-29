#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

ostream& operator << (ostream& out, const vector<int>& v){
    for (const auto& it: v){
        out << it << ' ';
    }
    return out;
}

void PrintReversePermutation(vector<int>& s){
    sort(s.rbegin(), s.rend());
    do {
        cout << s << '\n';
    } while(prev_permutation(s.begin(), s.end()));
}


int main()
{
    int n;
    cin >> n;
    vector <int> s;    
    for (int i=0; i<n; ++i){
        s.push_back(i+1);
    }

    PrintReversePermutation(s);

    
    return 0;
}