#include "profile.h"

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
    cin.tie(nullptr);
    {
        LOG_DURATION("not endl");
        for (int i = 0; i< 10000; ++i){
            int x;
            cin >> x;
            cout << x << "\n";
        }
    }

    {
        LOG_DURATION("endl");
        for (int i = 0; i< 10000; ++i){
            int x;
            cin >> x;
            cout << x << endl;
        }
    }
    return 0;
}