#include "profile.h"

#include <iostream>
#include <vector>
#include <set>
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
    vector<int> v;
    int input=0;
    for (int i=0; i<5; ++i){
        input += i;
        v.push_back(input);
    }
    if (v[5] == 0){
        v[6] = 1;
    }

    cout << v.size()<< endl;
    return 0;
}