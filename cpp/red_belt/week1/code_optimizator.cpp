// создание быстрого и эффективного кода
#include <string>
#include <vector>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

vector<string> GenerateBigVector() {
    vector<string> result;
    auto start = steady_clock::now();
    for (int i = 0; i<28000; ++i){
        result.push_back(to_string(i));
    }
    auto finish = steady_clock::now();
    auto duration = finish - start;
    cerr << "Cycle: " 
        << duration_cast<milliseconds> (duration).count()
        << endl;
    return result;
}

int main(){
    auto start = steady_clock::now();
    cout << GenerateBigVector().size() << endl;
    auto finish = steady_clock::now();
    auto duration = finish - start;
    cerr<< "Total: " 
        << duration_cast<milliseconds> (duration).count()
        << endl;
    return 0;
}