#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix);


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix){
       auto it =  binary_search(range_begin, range_end, prefix);
       
    }

int main(){

    return 0;
}