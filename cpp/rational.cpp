#include <iostream>
#include <numeric>
#include <sstream>
#include <set>
#include <map>
#include <vector>
using namespace std;

class Rational {
public:
  Rational(){
    fraction = Fraction();
  };
  Rational(int numerator, int denominator){
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
      int gcd = std::gcd(p, q); // @suppress("Function cannot be resolved")
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
  map<Rational, int> count;
  ++count[{1, 2}];
  ++count[{1, 2}];
  ++count[{2, 3}];

  for (const auto& item: count){
    cout << item.first.Numerator() << '/' << item.first.Denominator()
         << ':' << item.second << endl;
  }

  {
    const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
    if (rs.size() != 3) {
      cout << "Wrong amount of items in the set" << endl;
      return 1;
    }

    vector<Rational> v;
    for (auto x : rs) {
      v.push_back(x);
    }
    if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
      cout << "Rationals comparison works incorrectly" << endl;
      return 2;
    }
  }

  {
    map<Rational, int> count;
    ++count[{1, 2}];
    ++count[{1, 2}];

    ++count[{2, 3}];

    if (count.size() != 2) {
      cout << "Wrong amount of items in the map" << endl;
      return 3;
    }
  }
  cout << "OK" << endl;
  return 0;
}
