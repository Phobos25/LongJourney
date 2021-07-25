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
  
  string GetFullNameWithHistory(int year) {
    vector<string> all_first_names = FindPersonAllNamesAtYear(year, first_names_);
    vector<string> all_last_names  = FindPersonAllNamesAtYear(year, last_names_);
    reverse(begin(all_first_names), end(all_first_names));
    reverse(begin(all_last_names), end(all_last_names));
    
    if (all_first_names.empty() && all_last_names.empty()){
      return "Incognito";
    }else if (all_first_names.empty()){
      string name = PrintAllNames(all_last_names);
      return name + " with unknown first name";
    }else if (all_last_names.empty()){
      string name = PrintAllNames(all_first_names);
      return name + " with unknown last name";
    }
    string first_name = PrintAllNames(all_first_names);
    string last_name = PrintAllNames(all_last_names);
    return first_name + ' ' + last_name;    
}
private:  
  map<int, string> first_names_;
  map<int, string> last_names_;

  vector<string> FindPersonAllNamesAtYear(int year, const map<int, string>& names){
    vector<string> all_names = {};
    bool first = true;
    string last;
    for (const auto& [key, value]: names){
      if (key <= year){
        if (!value.empty()){
            if (first){
                first = false;
                last = value;
                all_names.push_back(value);         
            }else {
                if (last != value){
                  last = value;
                  all_names.push_back(value);         
                }
            }          
        }
      }
      else {
        break;
      }
    }
    return all_names;
  }

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

  string PrintAllNames(const vector<string>& names){
    string name = names[0];
    if (names.size() > 1u){        
        name += " (";
        for (size_t i = 1; i < names.size(); ++i){
            name += names[i];
            if (i+1 == names.size()){
              name += ')';  
            }else {
              name += ", " ;
            }            
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
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  

  return 0;
}


