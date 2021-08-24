#include "simple_vector.h"

#include <iostream>

using namespace std;

int main() {

    SimpleVector<int> sv(3);
    cout << sv.Size() << endl;
    SimpleVector<int> zero_v;
    cout << zero_v.Size() << endl;

}