#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

template <typename Iterator>
class IteratorRange {
private:    
    Iterator first, last;

public:
    IteratorRange (Iterator f, Iterator l)
        : first(f)
        , last(l)
        {            
        }
    Iterator begin() const {
        return first;
    }
    Iterator end() const {
        return last;
    }
};

template <typename T>
IteratorRange <typename vector<T>:: iterator> Head (vector<T>& v, size_t top){
    return{
        v.begin(), 
        next(v.begin(), min(top, v.size()))
    };
}

int main() {
    vector<int> v = {1,2,3,4,5};
    
    IteratorRange second_half{
        v.begin() + v.size() /2, v.end()
    };

    for (int it: second_half)   {
        cout << it << ' ';
    }
    
}