/*
 * name_lastname.cpp
 *
 *  Created on: Jun 3, 2021
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& name) {
    first_names_[year] = name;
  }

  void ChangeLastName(int year, const string& name) {
    last_names_[year] = name;
  }

  string GetFullName(int year) {
    const string first_name = FindPersonNameAtYear(year, first_names_);
    const string last_name  = FindPersonNameAtYear(year, last_names_);
    if (first_name.empty() && last_name.empty()){
      return "Incognito";
    }else if (first_name.empty()){
      return last_name + " with unknown first name";
    }else if (last_name.empty()){
      return first_name + " with unknown last name";
    }
    return first_name + ' ' + last_name;    
  }
 
private:  
  map<int, string> first_names_;
  map<int, string> last_names_;

  string FindPersonNameAtYear(int year, const map<int,string>& names){
    string name = "";
    for (const auto& [key, value]: names){
      if (key <= year){
        name = value;
      }
      else {
        break;
      }
    }
    return name;
  }
};


int main(){
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
    }
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }


  return 0;
}


