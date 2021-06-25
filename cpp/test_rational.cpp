#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>

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

class Rational {
public:
  Rational(){
    fraction = Fraction();
  };
  Rational(int numerator, int denominator){
    if (denominator == 0){
      throw invalid_argument("Invalid argument");
    }
    if (numerator*denominator >= 0){
      fraction = Fraction(abs(numerator), abs(denominator)) ;
    }else {
      fraction = Fraction(-abs(numerator), abs(denominator)) ;
    }

  };

  int Numerator() const{
    return fraction.num;
  };
  int Denominator() const{
    return fraction.denom;
  };
private:

  struct Fraction{
    int num;
    int denom;
    Fraction(int p=0, int q = 1){
      int gcdenom = std::gcd(p, q);
      num = p/gcdenom;
      denom = q/gcdenom;
    }
  };
  Fraction fraction;
};

void TestCommonDenominator(){
  {
    int p = 5;
    int q = 10;
    Rational r(1,2);
    int common_denom = std::gcd(p, q);
    int num = p/common_denom;
    int denom = q/common_denom;
    AssertEqual(r.Numerator(), num);
    AssertEqual(r.Denominator(), denom);

    Rational r2(100,200);
    AssertEqual(r2.Numerator(), num);
    AssertEqual(r2.Denominator(), denom);
  }

  {
    Rational r3(500,900);
    int num = 5;
    int denom = 9;
    AssertEqual(r3.Numerator(), num);
    AssertEqual(r3.Denominator(), denom);
  }

  {
    Rational r(30,6);
    AssertEqual(r.Numerator(), 5);
    AssertEqual(r.Denominator(), 1);
  }

}

void TestDefault(){
  {
    Rational r;
    AssertEqual(r.Numerator(), 0);
    AssertEqual(r.Denominator(), 1);
  }
  {
    Rational r(0,2);
    AssertEqual(r.Numerator(), 0);
    AssertEqual(r.Denominator(), 1);
  }
  {
    Rational r(0,10);
    AssertEqual(r.Numerator(), 0);
    AssertEqual(r.Denominator(), 1);
  }
}

void TestNegative(){
  {
    Rational r(-1,10);
    AssertEqual(r.Numerator(), -1);
    AssertEqual(r.Denominator(), 10);
  }
  {
    Rational r(1,-10);
    AssertEqual(r.Numerator(), -1);
    AssertEqual(r.Denominator(), 10);
  }
  {
    Rational r(1,-2);
    AssertEqual(r.Numerator(), -1);
    AssertEqual(r.Denominator(), 2);
  }
  {
    Rational r(-1,-10);
    AssertEqual(r.Numerator(), 1);
    AssertEqual(r.Denominator(), 10);
  }


}

int main() {
  TestRunner runner;
  runner.RunTest(TestCommonDenominator, "test common denominator");
  runner.RunTest(TestDefault, "test default");
  runner.RunTest(TestNegative, "test negative");
  // добавьте сюда свои тесты
  return 0;
}
