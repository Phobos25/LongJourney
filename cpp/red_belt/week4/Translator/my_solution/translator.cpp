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
  if (vocabulary.count(source) != 0|| vocabulary.count(target) !=0){

  } else {
    rus_dict.push_back(source);
    eng_dict.push_back(target);
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
  TestRunner tr;
  RUN_TEST(tr, TestSimple);

  return 0;
}
