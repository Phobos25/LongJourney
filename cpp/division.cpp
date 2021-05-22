#include <iostream>
#include <string>
using namespace std;

int main(){
    /*
    по условию задачи мы должне подавать положительные целые числа до 1000 000 
    что если мы подадим отрицательное число?
    Остановить? или выдать положительные ответ?
    10 2
    3 5
    4 4
    1000000 100000
    100000 1000000
    -4 4
    4 -4
    -5 -5
    11 0
    0 11
    */
    int a = 0, b =0 ;
    cin >> a >> b;
    
    if (a>=0 && b>=0){
        if (b != 0 ){
            cout << a/b << endl;        
        }
        else{
            cout << "Impossible" << endl;
        }   
    }
    

    return 0;
}