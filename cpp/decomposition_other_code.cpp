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

    string command;
    is >> command;

    if (command == "NEW_BUS") {
        q.type = QueryType::NewBus;
        is >> q.bus;
        int stop_count;
        is >> stop_count;
        q.stops.resize(stop_count);
        for (string& stop : q.stops) {
            is >> stop;
        }

    } else if (command == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    } else if (command == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    } else if (command == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }

  return is;
}

struct BusesForStopResponse {
    vector <string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {

    if (r.buses.empty()) os << "No stop";
    else {
        for (const string& bus : r.buses) os << bus << " ";
    }

  return os;
}

struct StopsForBusResponse {
    map <string, vector <string>> stops_buses;
    vector <string> order;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {

    if (r.order.size() == 0) os << "No bus";
    else {
        int k = 0;
        for (const string& stop : r.order) {
            os << "Stop " << stop << ":";
            k++;
            for (const string& bus : r.stops_buses.at(stop)) os << " " << bus;
            if (k != r.order.size()) os << endl;
        }
    }

  return os;
}

struct AllBusesResponse {
    map <string, vector <string>> all;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (r.all.empty()) os << "No buses";
    else {
        int k = 0;
        for (const auto& item : r.all) {
            os << "Bus " << item.first << ":";
            k++;
            for (const string& bus : item.second) os << " " << bus;
            if (k != r.all.size()) os << endl;
        }
    }
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
        buses_to_stops[bus] = stops;
        for (const string& stop : stops) stops_to_buses[stop].push_back(bus);
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    BusesForStopResponse res;

    if (stops_to_buses.count(stop) == 0) return res;
    for (const string& bus : stops_to_buses.at(stop)) res.buses.push_back(bus);

    return res;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    StopsForBusResponse res;

    if (buses_to_stops.count(bus) == 0) return res;
    else {
        for (const string& stop : buses_to_stops.at(bus)) {
            res.order.push_back(stop);
            if (stops_to_buses.at(stop).size() == 1) res.stops_buses[stop].push_back("no intercharge");
            else for (const string& other_bus : stops_to_buses.at(stop)) if (other_bus != bus) res.stops_buses[stop].push_back(other_bus);
        }
    }

    return res;
  }

  AllBusesResponse GetAllBuses() const {
    AllBusesResponse res;
    if (buses_to_stops.empty()) return res;
    else for (const auto& item : buses_to_stops) res.all[item.first] = item.second;

    return res;
  }

private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
};



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