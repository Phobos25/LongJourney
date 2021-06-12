#include <iostream>
#include <numeric>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <exception>
using namespace std;

class Rational {
public:
  Rational(){
    fraction = Fraction();
  };
  Rational(int numerator, int denominator){
    CheckDivisionByZero(denominator);
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
      int gcd = std::gcd(p, q); 
      num = p/gcd;
      denom = q/gcd;
    }
  };

  void CheckDivisionByZero(const int& denom){
    if (denom == 0){
      throw invalid_argument("Division by zero");
    }
  }
  Fraction fraction;
};

Rational operator+ (const Rational& lhs, const Rational& rhs){
  int numerator = lhs.Numerator()*rhs.Denominator() +
                  rhs.Numerator()*lhs.Denominator();
  int denominator = lhs.Denominator()*rhs.Denominator();
  return Rational(numerator, denominator);
};

Rational operator-(const Rational& lhs, const Rational& rhs){
  int numerator = lhs.Numerator()*rhs.Denominator() -
                  rhs.Numerator()*lhs.Denominator();
  int denominator = lhs.Denominator()*rhs.Denominator();
  return Rational(numerator, denominator);
}

Rational operator* (const Rational& lhs, const Rational& rhs){
  int numerator = lhs.Numerator()* rhs.Numerator();
  int denominator = lhs.Denominator() * rhs.Denominator();
  return Rational(numerator, denominator);
};

Rational operator/ (const Rational& lhs, const Rational& rhs){  
  int numerator = lhs.Numerator()* rhs.Denominator();
  int denominator = lhs.Denominator() * rhs.Numerator();
  if (denominator == 0){
    throw domain_error("Division by zero");
  }

  return Rational(numerator, denominator);
};


bool operator== (const Rational& lhs, const Rational& rhs){
    if (lhs.Denominator() == rhs.Denominator()){
      return lhs.Numerator() == rhs.Numerator();
    }
    else {
      return 0;
    }
  }

istream& operator>> (istream& stream, Rational& rational){
  int numerator = rational.Numerator();
  int denominator = rational.Denominator();
  string s1="";
  getline(stream, s1, '/');
  if (!s1.empty()){
    numerator = stoi(s1);
    string s2="";
    getline(stream, s2, ' ');
    if (!s2.empty()){
      denominator = stoi(s2);
      rational = Rational(numerator, denominator);
    }
  }
  return stream;
}

ostream& operator<< (ostream& stream, const Rational& rational){
  stream << rational.Numerator() << '/' << rational.Denominator();
  return stream;
}

bool operator< (const Rational& lhs, const Rational& rhs){
  return lhs.Numerator()*rhs.Denominator() < rhs.Numerator()*lhs.Denominator();
}

bool operator> (const Rational& lhs, const Rational& rhs){
  return lhs.Numerator()*rhs.Denominator() > rhs.Numerator()*lhs.Denominator();
}


int main(){
  try {
      Rational r(1, 0);
      cout << "Doesn't throw in case of zero denominator" << endl;
      return 1;
  } catch (invalid_argument& e) {
    cout << e.what() << endl;
  }
  try {
      auto x = Rational(1, 2) / Rational(0, 1);
      cout << "Doesn't throw in case of division by zero" << endl;
      return 2;
  } catch (domain_error& e) {
    cout << e.what() << endl;
  }
  cout << "OK" << endl;
  return 0;
}
