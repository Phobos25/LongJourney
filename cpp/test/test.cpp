#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string_view>
#include <string>
using namespace std;

vector<string_view> Split(const string_view& str) {  
  
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

void AddMethod(map<string_view, int>& method_stats, string_view method){
    if (method_stats.find(method) != method_stats.end()){
        ++method_stats[method];
    } else {
        ++method_stats["UNKNOWN"];
    }
}

int main(){
  map<string_view, int> data;
  data = {{"GET", 0}, {"POST", 0}, 
          {"PUT", 0}, {"DELETE", 0}, 
          {"UNKNOWN", 0}};
 
  const string first = "GET / HTTP/1.1";
  const string second = "PUT / HTTP/1.1";
  const string third = "DELETE / HTTP/1.1";
  const string fourth = "POST / HTTP/1.1";
  auto it = Split(first);
  AddMethod(data, it[0]);
  AddMethod(data, Split(second)[0]);
  AddMethod(data, Split(third) [0]);
  AddMethod(data, Split(fourth)[0]);

  for (auto [key, value]: data){
    cout << key << ": " << value << endl;
  }
  return 0;
}