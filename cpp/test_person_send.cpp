#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

void TestFirstName(){
    {
        Person person;
        person.ChangeFirstName(1970, "Sanya");
        person.ChangeFirstName(1971, "Alexander");
        person.ChangeFirstName(1975, "Alex");
        person.ChangeFirstName(1983, "Al");
        string full_name = person.GetFullName(1970);        
        AssertEqual(full_name, "Sanya with unknown last name");

        full_name = person.GetFullName(1974);
        AssertEqual(full_name, "Alexander with unknown last name");

        full_name = person.GetFullName(1977);
        AssertEqual(full_name, "Alex with unknown last name");      
    }
    {
        Person person;
        person.ChangeFirstName(1970, "Sanya");
        person.ChangeFirstName(1971, "Alexander");
        person.ChangeFirstName(1975, "Alex");
        person.ChangeFirstName(1983, "Al");
        person.ChangeFirstName(1975, "Al");
        string full_name = person.GetFullName(1977);
        AssertEqual(full_name, "Alex with unknown last name");

        full_name = person.GetFullName(1960);
        AssertEqual(full_name, "Incognito");
    }

    {
      Person person;
      string full_name = person.GetFullName(1977);
      AssertEqual(full_name, "Incognito");

      person.ChangeFirstName(1970, "Sanya");
      full_name = person.GetFullName(1977);
      AssertEqual(full_name, "Sanya with unknown last name");

      person.ChangeFirstName(1971, "Alex");
      full_name = person.GetFullName(1977);
      AssertEqual(full_name, "Alex with unknown last name");

      person.ChangeFirstName(1978, "Alexander");
      full_name = person.GetFullName(1977);
      AssertEqual(full_name, "Alex with unknown last name");

    }
}


void TestLastName(){
  {
    Person person;
    person.ChangeLastName(1970, "House");
    person.ChangeLastName(1971, "Holmes");
    person.ChangeLastName(1975, "Watson");    
    string full_name = person.GetFullName(1970);        
    AssertEqual(full_name, "House with unknown first name");

    full_name = person.GetFullName(1974);
    AssertEqual(full_name, "Holmes with unknown first name");

    full_name = person.GetFullName(1977);
    AssertEqual(full_name, "Watson with unknown first name");     

    full_name = person.GetFullName(1960);
    AssertEqual(full_name, "Incognito");     
  }

  {
    Person person;
    person.ChangeLastName(1970, "House");
    person.ChangeLastName(1971, "Holmes");
    person.ChangeLastName(1975, "Watson"); 
    string full_name = person.GetFullName(1977);
    AssertEqual(full_name, "Watson with unknown first name");

    person.ChangeLastName(1983, "Yankovich");
    person.ChangeLastName(1975, "Yankovich");
    full_name = person.GetFullName(1977);
    AssertEqual(full_name, "Yankovich with unknown first name");

    full_name = person.GetFullName(1960);
    AssertEqual(full_name, "Incognito");
  }

  {
    Person person;
    string full_name = person.GetFullName(1977);
    AssertEqual(full_name, "Incognito");

    person.ChangeLastName(1970, "Watson");
    full_name = person.GetFullName(1977);
    AssertEqual(full_name, "Watson with unknown first name");

    person.ChangeLastName(1971, "Holmes");
    full_name = person.GetFullName(1977);
    AssertEqual(full_name, "Holmes with unknown first name");

    person.ChangeLastName(1978, "Yankovich");
    full_name = person.GetFullName(1977);
    AssertEqual(full_name, "Holmes with unknown first name");
  }
}

void TestFullName(){
  {
    Person person;
    person.ChangeLastName(1970, "House");
    person.ChangeFirstName(1971, "Gregory");
    person.ChangeFirstName(1975, "Greg");    
    string full_name = person.GetFullName(1970);        
    AssertEqual(full_name, "House with unknown first name");
    
    full_name = person.GetFullName(1971);
    AssertEqual(full_name, "Gregory House");

    full_name = person.GetFullName(1975);
    AssertEqual(full_name, "Greg House");    

    full_name = person.GetFullName(1960);
    AssertEqual(full_name, "Incognito");     
  }

  {
    Person person;
    person.ChangeFirstName(1970, "House");
    person.ChangeLastName(1970, "Gregory");
    string full_name = person.GetFullName(1970);
    AssertEqual(full_name, "Gregory House");

    person.ChangeFirstName(1970, "Wilson");
    person.ChangeLastName(1970, "James");
    full_name = person.GetFullName(1975);
    AssertEqual(full_name, "Gregory House");    
  }  
}

int main() {
  TestRunner runner;
  runner.RunTest(TestFirstName, "TestFirstname");
  runner.RunTest(TestLastName, "TestLastname");
  runner.RunTest(TestFullName, "TestFullname");
  // добавьте сюда свои тесты
  return 0;
}
