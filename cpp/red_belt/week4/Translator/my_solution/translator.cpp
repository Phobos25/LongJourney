#include "test_runner.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Translator {
public:
  void Add(string_view source, string_view target);
  string_view TranslateForward(string_view source) const;
  string_view TranslateBackward(string_view target) const;

private:
  vector<string_view> rus_dict;
  vector<string_view> eng_dict;
  set<string_view> vocabulary;
};

void Translator::Add (string_view source, string_view target) {
  if (vocabulary.count(source) == 0){
    vocabulary.insert(source);
    rus_dict.push_back(source);
    eng_dict.push_back(target);
  } else {
    auto it = find(rus_dict.begin(), rus_dict.end(), source);    
    size_t index = it - rus_dict.begin();
    eng_dict[index] = target;
  }
}

string_view Translator::TranslateForward(string_view source) const{
  if (eng_dict.size() == 0 || rus_dict.size() == 0){
    return "";
  }
  for (size_t i = 0; i<rus_dict.size(); ++i){
    if (rus_dict[i] == source){
      return eng_dict.at(i);
    }
  }
  return "";
}

string_view Translator::TranslateBackward(string_view target) const{
  if (eng_dict.size() == 0 || rus_dict.size() == 0){
    return "";
  }
  for (size_t i = 0; i<eng_dict.size(); ++i){
    if (eng_dict[i] == target){
      return rus_dict.at(i);
    }
  }
  return "";
}


void TestSimple() {
  Translator translator;
  translator.Add(string("okno"), string("window"));
  translator.Add(string("stol"), string("table"));

  ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
  ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
  ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
}

int main() {
  // TestRunner tr;
  // RUN_TEST(tr, TestSimple);
  Translator trans;
  string rus = "dom";
  string eng = "house";
  trans.Add(rus, eng);
  cout << trans.TranslateForward(rus) << "\n";
  cout << trans.TranslateBackward(eng) << "\n";

  eng = "home";
  cout << "test after eng string has changed" << "\n";
  cout << trans.TranslateForward(rus) << "\n";
  cout << trans.TranslateBackward(eng) << "\n";
  
  trans.Add(rus, eng);
  cout << "test after adding a new word to our vector" << "\n";
  cout << trans.TranslateForward(rus) << "\n";
  cout << trans.TranslateBackward(eng) << "\n";
  return 0;
}
