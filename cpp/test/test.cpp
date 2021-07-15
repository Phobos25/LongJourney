#include "test_runner.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string s) {
    for (size_t i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

void TestEmpty(){
  {
    AssertEqual(IsPalindrom(" "), true);
    AssertEqual(IsPalindrom(""), true);
  }
}

void TestASymbol(){
  {
    AssertEqual(IsPalindrom("a"), true);
    AssertEqual(IsPalindrom("b"), true);
    AssertEqual(IsPalindrom("c"), true);
    AssertEqual(IsPalindrom("1"), true);
  }
}

void TestWords(){
  {
    AssertEqual(IsPalindrom("madam"), true);
    AssertEqual(IsPalindrom("moped"), false);
    AssertEqual(IsPalindrom("argentinamanitnegra"), true);
    AssertEqual(IsPalindrom("argentina manit negra"), false);
    AssertEqual(IsPalindrom("tommot"), true);
    AssertEqual(IsPalindrom("tonmot"), false);
    AssertEqual(IsPalindrom("asdsa"), true);
    AssertEqual(IsPalindrom("sadam"), false);
    AssertEqual(IsPalindrom("maddam"), true);
  }
}

int main() {
  TestRunner runner;
  runner.RunTest(TestEmpty, "test empty");
  runner.RunTest(TestASymbol, "test a symbol");
  runner.RunTest(TestWords, "test words");
  // добавьте сюда свои тесты
  return 0;
}
