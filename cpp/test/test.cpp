#include <iostream>
#include <vector>
#include <utility>

using namespace std;

template <typename Iterator>
class IteratorRange{
private:
    Iterator first, last;
public:
    IteratorRange( Iterator f, Iterator l)
        : first(f)
        , last(l)
        {

        }
};

int main() {
    vector<int> v = {1,2,3,4,5};
    pair p(1, false);
    cout << p.first << ' ' << p.second << endl;
    IteratorRange second_half(v.begin() + v.size() / 2, v.end());

    for (auto x: second_half){
        cout << x << ' ';
    }
}