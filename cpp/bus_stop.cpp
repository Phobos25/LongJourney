/*
 * bus_stop.cpp
 *
 *  Created on: Jun 2, 2021
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void AddNewBus(vector<string>& bus, const int& stop_count){
  for (int i=0; i<stop_count; ++i){
    string stop;
    cin >> stop;
    bus.push_back(stop);
  }
}

vector <string> GetBusesForStop(const map <string, vector<string>>& all_buses, string stop){
  bool flag = 0;
  vector<string> buses;
  for (auto& m:all_buses){
	for(const auto& item:m.second){
	  if (item == stop){
	    flag = 1;
	    break;
	  }
	  //if flag print bus name

	}
	if (flag == 1){
	  buses.push_back(m.first);
	  flag = 0;
	}
  }
  return buses;
}

void PrintStopsForBus(map<string, vector<string>>& all_buses, const string& bus){
  if (all_buses.size()<1){
	cout << "No bus";
	cout << endl;
  }
  for (auto& stop: all_buses[bus]){
	vector <string> buses = GetBusesForStop(all_buses, stop);
	if (buses.size() < 1){
	  cout << "No bus" << endl;
	}
	else {
	  if (buses.size() < 2 && buses[0] == bus){
	    cout << "Stop " << stop <<": no interchange" << endl;
	  }
	  else{
	    cout << "Stop " << stop <<':';
	    for (const auto& b:buses){
		  if (b != bus){
			cout << ' ' << b;
		  }
	    }
	    cout << endl;
	  }
	}
  }

}

void PrintAllStops(const map<string, vector<string>>& all_buses){
  if (all_buses.size() > 1){
    for(const auto& bus:all_buses){
	  cout << bus.first << ':';
	  for(auto& stop:bus.second){
		cout << ' ' << stop;
	  }
	  cout << endl;
	}
  }
  else{
	cout << "No buses" << endl;
  }
}

int main(){
  map<string, vector<string>> bus_route;
  int q;
  cin >> q;

  for (int i=0; i< q; ++i){
    string command;
    int stop_count;
    cin >> command;
    if (command =="NEW_BUS"){
      string bus;
      cin >> bus >> stop_count;
      AddNewBus(bus_route[bus], stop_count);
    }
    else if (command == "BUSES_FOR_STOP"){
      string stop;
      cin >> stop;
      vector <string> buses = GetBusesForStop(bus_route, stop);
      if (buses.size() < 1){
    	cout << "No stop";
      }
      else {
    	for (const auto& bus: buses){
		  cout << bus << ' ';
		}
      }
      cout << endl;
    }
    else if (command == "STOPS_FOR_BUS"){
      string bus;
      cin >> bus;
      PrintStopsForBus(bus_route, bus);
    }
    else if (command == "ALL_BUSES"){
      PrintAllStops(bus_route);
    }
  }
//  10
//  ALL_BUSES
//  BUSES_FOR_STOP Marushkino
//  STOPS_FOR_BUS 32K
//  NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
//  NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
//  BUSES_FOR_STOP Vnukovo
//  NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
//  NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
//  STOPS_FOR_BUS 272
//  ALL_BUSES
  return 0;
}


