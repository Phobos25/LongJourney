/*
 * bus_stop_3.cpp
 *
 *  Created on: Jun 3, 2021
 */

#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
	map <set<string>, int> bus_routes;
	int q;
	cin >> q;

	for (int i = 0; i<q; ++i){
		int n;
		cin >> n;
		set <string> new_route;
		for (int j=0; j< n; ++j){
			string s;
			cin >> s;
			new_route.insert(s);
		}
		if (bus_routes.count(new_route) != 0){
			cout << "Already exists for " << bus_routes[new_route];
		}
		else {
			int temp = bus_routes.size() + 1;
			bus_routes[new_route] = temp;
			cout << temp;
		}
	}
	return 0;
}


