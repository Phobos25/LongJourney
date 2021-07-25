#include <fstream>
#include <iostream>
using namespace std;

int main(){
  ifstream input("input.txt");
  ofstream output("output.txt");

  string line;
  if (input){
    while(getline(input,line)){
      cout << line << endl;
    }
  }
  return 0;
}

