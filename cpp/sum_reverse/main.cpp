#include "test_runner.h"
#include "sum_reverse_sort.h"
#include <iostream>

void TestSum(){
  AssertEqual(Sum(1,2), 3);
  AssertEqual(Sum(1,-2), -1);
  AssertEqual(Sum(0,2), 2);
  AssertEqual(Sum(-1,-2), -3);
  AssertEqual(Sum(0,0), 0);
}

void TestReverse(){
  AssertEqual(Reverse("madam"), "madam");
  AssertEqual(Reverse("a"), "a");
  AssertEqual(Reverse("vidra"), "ardiv");
  AssertEqual(Reverse("argentinamanitnegra"), "argentinamanitnegra");
  AssertEqual(Reverse("KFC"), "CFK");
}

void TestSortVector(){
  vector <int> v = {-3,2,1};
  vector <int> empty = {1,2,-3};
  Sort(v);
  for (const auto& it: v){
    cout << it << ' ';
  }
  cout << endl;
}

void TestAll(){
  TestRunner runner;
  runner.RunTest(TestSum, "TestSum");
  runner.RunTest(TestReverse, "TestReverse");
  runner.RunTest(TestSortVector, "TestSortVector");
}

int main(){
  TestAll();

  return 0;
}



