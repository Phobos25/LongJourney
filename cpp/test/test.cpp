#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> v1 = {1,2,3};
    vector <int> v2 = {3,2,1};

    vector<int> combined;
    combined.clear();
    combined.insert(combined.end(), v1.begin(), v1.end());
    combined.insert(combined.end(), v2.begin(), v2.end());

    for (const auto item: combined){
        cout << item << ' ';
    }
    
    cout << endl;

    cout << combined.size();
}