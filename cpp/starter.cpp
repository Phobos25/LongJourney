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
  string bus;
  vector<string> stops;
  BusesForStopResponse(string b, vector<string> s){
    bus = b;
    s = stops;
  };
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  // Реализуйте эту функцию
  return os;
}

struct StopsForBusResponse {
  // Наполните полями эту структуру
  string stop;
  vector<string> buses;
  StopsForBusResponse(string s, string b){
    stop = s;
    buses.push_back(b);
  }
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
  return os;
}

struct AllBusesResponse {
  // Наполните полями эту структуру
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // Реализуйте эту функцию
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
    buses_to_stops.push_back(BusesForStopResponse(bus, stops));
    for (const string stop:stops){
      for (size_t i =0; i<stops_to_buses.size(); ++i){
        if (stops_to_buses[i].stop == stop){
          stops_to_buses[i].buses.push_back(bus);
        }
      }
      stops_to_buses.push_back(StopsForBusResponse(stop, bus));
    }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    // Реализуйте этот метод
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    // Реализуйте этот метод
  }

  AllBusesResponse GetAllBuses() const {
    // Реализуйте этот метод
  }
private:
  vector<BusesForStopResponse> buses_to_stops;
  vector<StopsForBusResponse> stops_to_buses;
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
