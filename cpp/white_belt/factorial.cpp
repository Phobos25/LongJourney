#include <iostream>

using namespace std;

int Factorial(int f){
    if (f <= 0){
        return 1;
    }    
    else {
        return f* Factorial(f-1);
    }
    
}

int main(){
    int i;
    cin >> i;
    cout << Factorial(i);
    return 0;
}