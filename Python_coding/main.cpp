/*
 * main.cpp
 *
 *  Created on: May 7, 2022
 *      Author: igorpetrov
 */

#include <iostream>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;

string next_sequence(string s){
  int counter_close = 0;
  int counter_open = 0;
  for (int i = s.length()-1; i > 0; --i){
    if (s[i] == '(') {
        ++counter_open;
        if (counter_close > counter_open) break;
    }
    else {
      ++counter_close;
    }
  }
  // начиная с символа с индексом "length(s) - counter_open - counter_close"
  //  удаляем все символы (индексация с 0)
  s.erase(s.end()-counter_open-counter_close, s.end());
  if (s.length() == 0){
    return "No Solution";
  }
  else {
    s += ")";
    for (int j=0; j<counter_open; ++j){
      s += "(";
    }
    for (int j=0; j < counter_close-1; ++j){
      s += ")";
    }
  }
  return s;
}

bool isValid(string s) {
  if (s.length() % 2 == 1) return false;

  deque<char> stack;
  map<char, char> validParenLookup { {'}', '{'}, {']', '['}, {')', '('} };

  for (uint i = 0; i < s.length(); i ++) {
    if (validParenLookup.find(s[i]) == validParenLookup.end()) {
      stack.push_front(s[i]);
      continue;
    }
    if (stack.front() != validParenLookup[s[i]]) return false;
    stack.pop_front();
  }
  return stack.size() == 0;
}

int main(){
  string s = "(())";
  cout << isValid(s) << endl;

  return 0;
}



