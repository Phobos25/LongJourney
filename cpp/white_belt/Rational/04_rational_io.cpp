#include <iostream>
#include <numeric>
#include <sstream>
using namespace std;

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        fraction = Fraction();
    }

    Rational(int numerator, int denominator) {
        if (numerator*denominator >= 0){
           fraction = Fraction(abs(numerator), abs(denominator)) ;
        }else {
            fraction = Fraction(-abs(numerator), abs(denominator)) ;
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
    Fraction(int p=0, int q = 1){
      int gcd = std::gcd(p, q); 
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
  int numerator = lhs.Numerator()* rhs.Denominator();
  int denominator = lhs.Denominator() * rhs.Numerator();
  return Rational(numerator, denominator);
};

istream& operator>> (istream& stream, Rational& rational){
  int numerator;
  int denominator;
  char c;
  stream >> numerator >> c >> denominator;
  if (stream && c == '/'){
      rational = Rational(numerator, denominator);
  }
  return stream;
}

ostream& operator<< (ostream& stream, const Rational& rational){
  stream << rational.Numerator() << '/' << rational.Denominator();
  return stream;
}


int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}
