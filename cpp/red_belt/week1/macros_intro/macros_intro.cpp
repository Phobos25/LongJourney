#include <iostream>
#include <string>
#include "test_runner.h"
#include "rational.h"

using namespace std;

#define ASSERT_EQUAL(x,y, m) \
    AssertEqual(x,y,m)

void TestDefaultConstructor() {
    const Rational defaultConstructed;
    AssertEqual(
        defaultConstructed.Numerator(), 0,
        "Default constructor numerator"
    );
    AssertEqual(
        defaultConstructed.Denominator(),1,
        "Default constructor denominator"
    );
}

void TestConstruction() {
    const Rational r(3,12);
    AssertEqual(r.Numerator(), 1, "3/12 numerator");
    AssertEqual(r.Denominator(), 4, "3/12 denominator");
}

int main(){
    TestRunner tr;
    tr.RunTest(TestDefaultConstructor, "TestDefaultConstructor");
    tr.RunTest(TestConstruction, "TestConstruction");
    return 0;
}