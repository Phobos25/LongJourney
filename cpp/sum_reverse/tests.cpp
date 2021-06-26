#include "tests.h"
#include "test_runner.h"
#include "sum_reverse_sort.h"

using namespace std;
void TestSum(){    
    AssertEqual(Sum(1,2), 3);
    AssertEqual(Sum(5,5), 10);
    AssertEqual(Sum(0,2), 2);
    AssertEqual(Sum(-1,2), 1);
    AssertEqual(Sum(-1,-2), -3);   
};

void TestReverseString(){
    AssertEqual(Reverse("madam"), "madam");
    AssertEqual(Reverse("milan"), "nalim");
};

void TestSortVector(){
    vector <int> v = {3, 2, 1};
    AssertEqual(Sort(v), {1,2,3});
    AssertEqual(Sort({7, 8, 0}), {0,7,8});
};

void TestAll() {
    TestRunner runner;
    runner.RunTest(TestSum, "TestSum");
    runner.RunTest(TestSortVector, "TestSortVector");
    runner.RunTest(TestReverseString, "TestReverseString");    
}