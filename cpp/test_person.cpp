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

class Person {
public:
 void ChangeFirstName(int year, string first_name) {
    // добавить факт изменения имени на first_name в год year
    if (!IsChangedFirstName(year)){
      data[year].firstname = first_name;
      UpdateFirstName(year, first_name);
    }
  }

  void ChangeLastName(int year, string last_name) {
    // добавить факт изменения фамилии на last_name в год year
    if(!IsChangedLastName(year)){
      data[year].lastname = last_name;
      UpdateLastName(year, last_name);
    }
  }

  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
    sort(begin(years), end(years));
    upper = upper_bound(begin(years), end(years), year);
    int index = upper - years.begin() - 1 ;

    if (index < 0){
      index= 0;
    }
    if (years[index] > year){
      return "Incognito";
    }

    int dyear = years[index];

    if (data[dyear].firstname.length()>0 && data[dyear].lastname.length()>0){
      return data[dyear].firstname + ' ' + data[dyear].lastname;
    }
    else if(data[dyear].firstname.length()>0 && data[dyear].lastname.length()==0){
      return data[dyear].firstname + " with unknown last name";
    }
    else if(data[dyear].firstname.length()==0 && data[dyear].lastname.length()>0){
      return data[dyear].lastname + " with unknown first name";
    }
    return "Incognito";
  }
private:
  struct changed{
    bool first = false;
    bool last = false;
  };
  struct fullname{
    string firstname;
    string lastname;
    changed is_changed;
  };

  vector<int>::iterator upper, lower;
  vector<int> years;
  map<int, fullname> data;

  int GetIndex(const vector<int>& v, int K)
  {
      auto it = find(v.begin(), v.end(), K);

      // If element was found
      if (it != v.end())
      {
          // calculating the index
          // of K
          int index = it - v.begin();
          return index;
      }
      else {
          // If the element is not
          // present in the vector
          return -1;
      }
  }

  bool IsChangedFirstName(const int& year){
    if(data[year].is_changed.first == 0){return false;}
    else {return true;}
  }

  bool IsChangedLastName(const int& year){
    if(data[year].is_changed.last == 0){return false;}
        else {return true;}
  }

  void UpdateFirstName(const int& year, const string& name){
    years.push_back(year);
    sort(begin(years), end(years));
    int index = GetIndex(years, year);
    for (int i=index; i<years.size(); ++i){
      if (data[years[i]].firstname.length() != 0){
        data[years[i]].firstname = name;
      }
    }
    upper = upper_bound(begin(years), end(years), year);
    index = upper - years.begin() - 1;
    if (index < 0){
      index = 0;
    }
    if (years[index] == year){
      index-=1;
    }
    data[year].lastname = data[years[index]].lastname;
    data[year].is_changed.first = true;
  }

  void UpdateLastName(const int& year, const string& name){
    years.push_back(year);
    sort(begin(years), end(years));
    int index = GetIndex(years, year);
    for (int i = index; i< years.size(); ++i){
      if (data[years[i]].lastname.length() != 0){
        data[years[i]].lastname = name;
      }
    }
    upper = upper_bound(begin(years), end(years), year);
    index = upper - years.begin() - 1;
    if (index < 0){
      index = 0;
    }
    if (years[index] == year){
      index-=1;
    }
    data[year].firstname = data[years[index]].firstname;
    data[year].is_changed.last = true;
  }
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
    AssertEqual(full_name, "Watson with unknown first name");

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

}

int main() {
  TestRunner runner;
  runner.RunTest(TestFirstName, "TestFirstname");
  runner.RunTest(TestLastName, "TestLastname");
  runner.RunTest(TestFullName, "TestFullname");
  // добавьте сюда свои тесты
  return 0;
}
