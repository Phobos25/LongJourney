/*
 * cap_dict.cpp
 *
 *  Created on: Jun 1, 2021
 */

#include <iostream>
#include <map>
#include <string>
using namespace std;

void ChangeCapital(map <string, string>& c_c, string& s1, string& s2){

	if (c_c[s1].length() < 1){
	  c_c[s1] = s2;
	  cout << "Introduce new country " << s1 << " with capital " << s2 << endl;
	}
	else {
	  if (c_c[s1] == s2){
		cout << "Country " << s1 << " hasn't changed its capital" << endl;
		}
	  else {
		string old_cap = c_c[s1];
		c_c[s1] = s2;
		cout << "Country " << s1 << " has changed its capital from " << old_cap << " to "<< s2 << endl;
	  }
	}
}

void Rename(map<string, string>& c_c, string& s1, string& s2){
	int flag = 0;
	for (const auto& item : c_c){
	  if (item.first == s2){
		flag = 1;
	  }
	}

	if (c_c[s1].length() > 1 && s1 != s2 && flag != 1){
	  string capital = c_c[s1];
	  c_c.erase(s1);
	  c_c[s2] = capital;
	  cout << "Country " << s1 << " with capital " << capital << " has been renamed to " << s2 << endl;
	}
	else {
	  cout << "Incorrect rename, skip" << endl;
	  if (c_c[s1].length() < 1){
		c_c.erase(s1);
	  }
	}
}

void About(map<string, string>& c_c, string& s1){

	if (c_c[s1].length() < 1){
	  cout << "Country " << s1 << " doesn't exist" << endl;
	  c_c.erase(s1);
	}
	else {
	  cout << "Country " << s1 << " has capital " << c_c[s1] << endl;
	}
}

void Dump (const map <string, string>& c_c){
	// dump
	if (c_c.size() < 1){
	  cout << "There are no countries in the world " << endl;
	}
	else {
	  for (const auto& item: c_c){
		cout << item.first << '/' << item.second << endl;
	  }
	}
}

int main(){
	map <string, string> country_capital;
	// input number of queries
	int q;
	string com;
	cin >> q;

	for (int i=0; i<q; ++i){
	  cin >> com;
	  string first_c, second_c;

	  if (com == "CHANGE_CAPITAL"){
		//choose country
		cin >> first_c;
		//choose capital name
		cin >> second_c;
		ChangeCapital(country_capital, first_c, second_c);
		}
	  if (com == "RENAME") {
		cin >> first_c;
		cin >> second_c;
		Rename(country_capital, first_c, second_c);
		// choose a country by name
		// and rename it
	  }

	  if (com == "ABOUT"){
		cin >> first_c;
		About(country_capital, first_c);	// show country's capital
	  }

	  // show all capitals
	  if (com == "DUMP"){
		Dump(country_capital);
	  }
	}
//	10
//	CHANGE_CAPITAL RussianEmpire Petrograd
//	RENAME USSR RussianEmpire
//	DUMP
//	ABOUT USSR
//	DUMP
//	RENAME RussianEmpire RussianEmpire
//	DUMP
//	CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia
//	RENAME RussianEmpire UnitedStatesOfBrazil
//	DUMP

	return 0;
}


