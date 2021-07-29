#include "rational.h"


using namespace std;
 
Rational::Rational(int nn, int dd) {
    if (nn*dd >= 0){
        fraction = Fraction(abs(nn), abs(dd)) ;
    }else {
        fraction = Fraction(-abs(nn), abs(dd)) ;
    }
}

int Rational::Numerator() const {
    return fraction.num;
}

int Rational::Denominator() const {
    return fraction.denom;
}