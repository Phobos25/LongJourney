#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(){
	map <int, vector<string>> bus_routes;
	int q;
	string stops;
	cin >> q;
	int count = 0;
	bool flag = 0;
	for (int i=0; i<q; ++i){
		int n;
		cin >> n;
	  	vector<string> new_route(n);
	  	flag = 0;
	  	for (string& s: new_route){
	  		cin >> s;
	  	}
	  	if (bus_routes.size() < 1){
	  		bus_routes[++count] = new_route;
	  		cout << "New bus " << count << endl;
	  	}
	  	else{		  					
	  		for (const auto& route:bus_routes){
	  			if (route.second == new_route){
	  				cout << "Already exists for " << route.first << endl;
	  				flag = 1;
	  				break;
	  			}	
	  		}

	  		if (flag != 1){
	  			bus_routes[++count] = new_route;
	  			cout << "New bus " << count << endl;
	  		}

	  		}
	}
	return 0;
}