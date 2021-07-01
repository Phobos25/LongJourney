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
    size_t third = elements.size()/3;  
    size_t second_third = third*2;     
    
    vector<typename RandomIt::value_type> first_vector(elements.begin(), elements.begin()+third);
    vector<typename RandomIt::value_type> second_vector(elements.begin()+third, elements.begin()+second_third);
    vector<typename RandomIt::value_type> last_vector(elements.begin()+second_third, elements.end());

    // Вызвать функцию MergeSort от каждой трети вектора.
    MergeSort(begin(first_vector), end(first_vector));
    MergeSort(begin(second_vector), end(second_vector));
    MergeSort(begin(last_vector), end(last_vector));

    vector<typename RandomIt::value_type> temp;
    merge(begin(first_vector), end(first_vector),
          begin(second_vector), end(second_vector),
          back_inserter(temp));
    merge(begin(temp), end(temp), 
          begin(last_vector), end(last_vector),
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