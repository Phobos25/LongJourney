#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    deque <int*> my_deque; 

    int *p1 = new int(1);
    int *p2 = new int(2);
    int *p3 = new int(3);

    my_deque.push_back(p1);
    my_deque.push_back(p2);
    my_deque.push_back(p3);
    while( !my_deque.empty() ) {
        cout << my_deque.front() << ": " << *my_deque.front() << endl;
            delete my_deque.front();        
        auto it = find(my_deque.begin(), my_deque.end(), my_deque.front());
        my_deque.erase(it);
        }
    return 0;
}