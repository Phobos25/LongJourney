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

//
//    if (IsChangedFirstName(dyear) && IsChangedLastName(dyear)){
//      string result = data[dyear].firstname + ' ' + data[dyear].lastname;
//      return result;
//    }
//    else if (IsChangedFirstName(dyear) && !IsChangedLastName(dyear)){
//      string result = data[dyear].firstname + " with unknown last name";
//      return result;
//    }
//    else if (!IsChangedFirstName(dyear) && IsChangedLastName(dyear)){
//      string result = data[dyear].lastname + " with unknown first name";
//      return result;
//    }
    return "Incognito";

  }

  void PrintAll(){
    for(auto& i: data){
      cout << i.first << ": ";
      cout << i.second.firstname << ' ' << i.second.lastname << endl;
    }
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


