#include "responses.h"

using namespace std;

ostream& operator << (ostream& os, const BusesForStopResponse& r) {

  if (r.buses.empty()) os << "No stop";
  else {
    for (const std::string& bus : r.buses) os << bus << " ";
  }
  return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {

  if (r.order.size() == 0) os << "No bus";
  else {
    size_t i = 0;
    for (const string& stop : r.order) {
      os << "Stop " << stop << ":";
      ++i;
      for (const string& bus : r.stops_buses.at(stop)) os << " " << bus;
      if (i != r.order.size()) {
        os << endl;
      }
    }
  }

  return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  if (r.all.empty()) os << "No buses";
  else {
    size_t i = 0;
    for (const auto& item : r.all) {
      os << "Bus " << item.first << ":";
      ++i;
      for (const string& bus : item.second){
        os << " " << bus;
      }
      if (i != r.all.size()) {
        os << endl;
      }
    }
  }
  return os;
}

