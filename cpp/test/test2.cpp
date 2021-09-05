#include <iostream>
#include <string_view>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string_view> Split(const string& s) {
  string_view str = s;
  
  vector<string_view> result;
  size_t pos = 0;  //string view не дружит с итераторами
  const size_t pos_end = str.npos; //работает только с подряд идущими строками

  while (true){
    size_t space = str.find(' ', pos); // ищем пустую строку с позиции pos
    
    result.push_back(
      space == pos_end
      ? str.substr(pos)
      : str.substr(pos, space-pos)
    );

    if (space == pos_end){
      break;
    } else {
      pos = space + 1;
    }
  }
  return result;
}

int main2() {
  string words = "two words";
  const auto word = Split("a b c");
  cout << word[0] << endl; 
}