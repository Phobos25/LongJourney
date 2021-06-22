#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  // Реализуйте эту функцию  
  string query, bus, stop; 
  is >> query;
  if (query == "NEW_BUS")  {
    q.type = QueryType::NewBus;
    is >> q.bus;
    int stop_count;
    is >> stop_count;    
    q.stops.resize(stop_count);
    for (string& s: q.stops){
      cin >> s;      
    }
  }else if (query == "BUSES_FOR_STOP")  {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  }else if (query == "STOPS_FOR_BUS"){
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  }else if (query == "ALL_BUSES"){
    q.type = QueryType::AllBuses;    
  }else {
    return is;
  }

  return is;
}

struct BusesForStopResponse {
  map <string, vector<string>> buses_for_stop; 
  string stop; 
  BusesForStopResponse(const string& bus, const vector<string>& stops){
    buses_for_stop[bus] = stops;
  }
  BusesForStopResponse();
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  // Реализуйте эту функцию

  return os;
}

struct StopsForBusResponse {
  map <string, vector<string>> stops_for_bus;
  map <string, vector<string>> buses_for_stop;    
  StopsForBusResponse(const string& stop, const string& bus){
    stops_for_bus[stop].push_back(bus);    
  }
  size_t GetSize(){    
    return stops_for_bus.size();
  }
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
  return os;
}

struct AllBusesResponse {
  // Наполните полями эту структуру
  map <string, vector<string>> stops_for_bus;
  map <string, vector<string>> buses_for_stop;    
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // Реализуйте эту функцию
  return os;
}

class BusManager {
public:
  BusManager();

  void AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
    buses_for_stop = BusesForStopResponse(bus, stops);    
    for (const string stop:stops){     
      stops_for_bus.stops_for_bus[bus].push_back(stop);
    }   
    all_buses.buses_for_stop = buses_for_stop.buses_for_stop;
    all_buses.stops_for_bus = stops_for_bus.stops_for_bus; 
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    return buses_for_stop;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    return stops_for_bus;
  }

  AllBusesResponse GetAllBuses() const {    
    return all_buses;
  }
private:
  BusesForStopResponse buses_for_stop;
  StopsForBusResponse stops_for_bus;  
  AllBusesResponse all_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
