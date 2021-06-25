#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

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
