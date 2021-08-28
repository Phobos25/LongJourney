#include <iostream>
#include <vector>

using namespace std;

void LogVectorParams(const vector<int>& v){
    cout << "Length = " << v.size() << ", " <<
          "capacity = " << v.capacity() << "\n";
    const int* data = v.data();        
    for (size_t i = 0; i < v.capacity(); ++i){
        cout << data[i] << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> v = {1,2,3};
    LogVectorParams(v);
    v.push_back(4);
    LogVectorParams(v);   
    // уменьшение capacity до размеров size вектора
    v.shrink_to_fit(); 
    LogVectorParams(v);   
    return 0;
}