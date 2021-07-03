#include <iostream>
#include <vector>
#include <numeric>
#include "compute.h"
#include "statics.h"
#include "budget_manager.h"

using namespace std;

int main() {
  cout.precision(25);
  vector<double> money(DAY_COUNT, .0);
  size_t num_queries;
  cin >> num_queries;

  for (size_t i = 0; i < num_queries; ++i) {
    string command, date_from, date_to;
    cin >> command >> date_from >> date_to;
    Date from = Date::FromString(date_from);
    Date to = Date::FromString(date_to);
    auto start_indx = ComputeDaysDiff(from, START_DATE);
    auto finish_indx = ComputeDaysDiff(to, START_DATE);
    if (command == "Earn") {
      double value;
      cin >> value;
      value /= ComputeDaysDiff(to, from) + 1;
      for (int j = start_indx; j <= finish_indx; ++j) {
        money[j] += value;
      }
    } else {
      cout << accumulate(money.begin() + start_indx, money.begin() + finish_indx + 1, 0.) << '\n';
    }
  }

  return 0;
}
