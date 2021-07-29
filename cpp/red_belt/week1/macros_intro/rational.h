#pragma once

#include <numeric>
#include <iostream>
#include <numeric>
#include <sstream>
class Rational{
public:
    Rational () = default;
    Rational (int nn, int dd);

    int Numerator() const;
    int Denominator() const;
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