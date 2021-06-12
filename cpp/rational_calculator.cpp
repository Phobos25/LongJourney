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
      int gcd = std::gcd(p, q);
      num = p/gcd;
      denom = q/gcd;
    }
  };
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
  stream >> numerator;
  if (stream.peek() == '/'){
    stream.ignore(1);
  }else{
    cout << "invalid argument" << endl;
    return stream;
  }
  stream >> denominator;
  rational = Rational(numerator, denominator);
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
  Rational r1,r2;
  char c;


  try {
    cin >> r1;
    cin >> c;
  } catch(invalid_argument&){
    cout << "Invalid argument" << endl;
  }

  if (c == '+'){
    try {
      cin >> r2;
      Rational r = r1+r2;
      cout << r.Numerator() << '/' << r.Denominator()<<endl;
    }catch (invalid_argument&){
      cout << "Invalid argument" << endl;
    }
  }else if(c =='-'){
    try {
      cin >> r2;
      Rational r = r1-r2;
      cout << r.Numerator() << '/' << r.Denominator()<<endl;
    }catch (invalid_argument&){
      cout << "Invalid argument" << endl;
    }
  }else if(c =='*'){
    try{
      cin >> r2;
      Rational r = r1*r2;
      cout << r.Numerator() << '/' << r.Denominator()<<endl;
    }catch (invalid_argument&){
      cout << "Invalid argument" << endl;
    }
  }else if (c=='/'){
    try {
      cin >> r2;
      Rational r = r1/r2;
      cout << r.Numerator() << '/' << r.Denominator()<<endl;
    } catch (invalid_argument&){
      cout << "Invalid argument" << endl;
    } catch(domain_error&){
      cout << "Division by zero" << endl;
    }
  }

  return 0;
}
