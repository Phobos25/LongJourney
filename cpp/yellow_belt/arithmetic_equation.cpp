/* arithmetic_equation.cpp
 *  Created on: Jul 8, 2021 */
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void ArithmeticExpression(string& str, char symb, int arg){
  stringstream stream;
  if (str.size() < 2u){
    stream << str << ' ' << symb << ' ' << arg;
  }else if (symb == '*' || symb == '/'){
    stream << '(' << str << ')' << ' ' << symb << ' ' << arg;
  }else {
    stream << str << ' ' << symb << ' ' << arg;
  }

  str = stream.str();
}

int main() {
  int x;
  size_t max_commands;
  cin >> x >> max_commands;
  string str = to_string(x);
  for (size_t i=0; i<max_commands; ++i){
    char symb;
    int arg;
    cin >> symb >> arg;
    ArithmeticExpression(str, symb, arg);
  }
  cout << str;
//  8
//  3
//  * 3
//  - 6
//  / 1
  return 0;
}

