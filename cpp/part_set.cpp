#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border){
    vector <T> result;

    auto border_it = find_if(
    elements.begin(), elements.end(),
    [border](T element) {
      return element > border;
        }
    );

    for (auto it = border_it; 
        it != elements.end(); ++it){
            result.push_back(*it);
        }

    return result;
}


int main() {
 
    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;
    
    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
    return 0;
}