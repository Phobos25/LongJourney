#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
  ifstream input("input.txt");

  int i,j; //размерность таблицы. i - строки, j - столбцы
  int width = 10; //ширина между числами в таблице
  double a;
  vector<double> values;

  input >> i >> j;

  for (int k=0; k<i; ++k){
    for (int l=0; l<j-1; ++l){
      input >> a;
      input.ignore(1);
      cout << setw(width) << a << ' ';
    }
    input >> a;
    if (k == i-1){
      cout << setw(width) << a;
    }else {
      cout << setw(width) << a << endl;
    }

  }

  return 0;
}

