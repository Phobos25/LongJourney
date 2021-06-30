#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include "compute.h"

using namespace std;

void PrintStats(vector<Person> persons){  

   
  cout << "Median age = "
       << ComputeMedianAge(begin(persons), end(persons)) << endl;
  auto it_all = partition(begin(persons), end(persons),
            [] (const Person& pers){
                return pers.gender == Gender::FEMALE;
            });
  cout << "Median age for females = "
       << ComputeMedianAge(begin(persons), it_all) << endl;
  cout << "Median age for males = "
       << ComputeMedianAge(it_all, end(persons)) << endl;
 
  vector<Person> men; 
  auto it_men = copy_if(begin(persons), end(persons),
              back_inserter(men),
              [] (const Person& pers){
                return pers.gender == Gender::MALE;
              } );

  persons.erase(it_all, end(persons));

  auto it_ewomen = partition(begin(persons), end(persons),
              [] (const Person& pers){
                return pers.is_employed == true;
              });

  cout << "Median age for employed females = "
       << ComputeMedianAge(begin(persons), it_ewomen) << endl;
  cout << "Median age for unemployed females = "
       << ComputeMedianAge(it_ewomen, end(persons)) << endl;

  auto it_emen = partition(begin(men), end(men),
              [] (const Person& pers){
                return pers.is_employed == true;
              });
  cout << "Median age for employed males = "
       << ComputeMedianAge(begin(men), it_emen) << endl;
  cout << "Median age for unemployed males = "
       << ComputeMedianAge(it_emen, end(men)) << endl;

}



int main() {
    vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
    };
    PrintStats(persons);
    return 0;
}