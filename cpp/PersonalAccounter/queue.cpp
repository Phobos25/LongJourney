#include <deque>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main() {
    deque<int> d;
    int x = 1;
    d.push_back(x); //добалвение элемента в конец вектора
    d.pop_back(); // удаление элемента вектора с конца
    
    d.push_front(0); //добавление в начало
    for (auto const i: d){
        cout << i << ' ';
    }
    d.pop_front(); //удаление из начала

    
    return 0;
}