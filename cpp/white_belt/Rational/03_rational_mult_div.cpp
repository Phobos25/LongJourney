#include <iostream>
#include <numeric>
using namespace std;

int GreatestCommonDivisor (int p, int q){
    if (q==0){
      return p;
    }else {
      return GreatestCommonDivisor(q, p%q);
    }
  }

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        fraction = Fraction();
    }

    Rational(int numerator, int denominator) {
        fraction = Fraction(numerator, denominator);
        
        if (denominator < 0){
          denominator = - denominator;
          numerator = - numerator;
        }
    }

    int Numerator() const {
        return fraction.num;
    }

    int Denominator() const {
        return fraction.denom;
    }

private: 
 struct Fraction{
    int num;
    int denom;
    Fraction(){
      num = 0;
      denom = 1;
    }
    Fraction(int p, int q){
      int gcd = GreatestCommonDivisor(p, q); 
      num = p/gcd;
      denom = q/gcd;
    }
  };  

  Fraction fraction;
};

// Реализуйте для класса Rational операторы ==, + и -
bool operator== (const Rational& lhs, const Rational& rhs){
    if (lhs.Denominator() == rhs.Denominator()){
      return lhs.Numerator() == rhs.Numerator();
    }
    else {
      return 0;
    }
  }

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

// Реализуйте для класса Rational операторы * и /
Rational operator* (const Rational& lhs, const Rational& rhs){
  int numerator = lhs.Numerator()* rhs.Numerator();
  int denominator = lhs.Denominator() * rhs.Denominator();
  return Rational(numerator, denominator);
};

Rational operator/ (const Rational& lhs, const Rational& rhs){  
  return lhs*Rational(rhs.Denominator(), rhs.Numerator());
};

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
