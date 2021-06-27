#include "bus_manager.h"

using namespace std;

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
  buses_to_stops[bus] = stops;
  for (const string& stop : stops) {
    stops_to_buses[stop].push_back(bus);
  }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {

  BusesForStopResponse result;

  if (stops_to_buses.count(stop) == 0) {
    return result;
  }
  for (const string& bus : stops_to_buses.at(stop)) {
    result.buses.push_back(bus);
  }

  return result;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {

  StopsForBusResponse result;

  if (buses_to_stops.count(bus) == 0) return result;
  else {
    for (const string& stop : buses_to_stops.at(bus)) {
      result.order.push_back(stop);
      if (stops_to_buses.at(stop).size() == 1) result.stops_buses[stop].push_back("no interchange");
      else for (const string& other_bus : stops_to_buses.at(stop)) if (other_bus != bus) result.stops_buses[stop].push_back(other_bus);
    }
  }

  return result;
}

AllBusesResponse BusManager::GetAllBuses() const {

  AllBusesResponse result;

  if (buses_to_stops.empty()) {
    return result;
  }else {
    for (const auto& item : buses_to_stops) {
      result.all[item.first] = item.second;
    }
  }

  return result;
}

