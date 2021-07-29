#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    // Если диапазон содержит меньше 2 элементов, выйти из функции.
    if ((range_end - range_begin) < 3){ return; }

    // Создать вектор, содержащий все элементы текущего диапазона.
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
        
    // Разбить вектор на три равные части. 
    auto third = begin(elements) + elements.size()/3;  
    auto second_third = third + elements.size()/3;     
    
    // Вызвать функцию MergeSort от каждой трети вектора.
    MergeSort(elements.begin(), third);
    MergeSort(third, second_third);
    MergeSort(second_third, elements.end());

    vector<typename RandomIt::value_type> temp;

    merge(begin(elements), third,
          third, second_third,
          back_inserter(temp));
    merge(begin(temp), end(temp), 
          second_third, end(elements),
          range_begin);
}

int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}