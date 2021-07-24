/*
 * get_inline.cpp
 *
 *  Created on: May 28, 2021
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void Quiet(vector <int>& worry, int n){

	auto it = find(worry.begin(), worry.end(), n);

	if (it != worry.end()) {
	  using std::swap;

	  swap(*it, worry.back());
	  worry.pop_back();
	}
}

void GetInLine(vector <int>& line, int n){
	int z = line.size();
	for (int i=z; i<z+n; ++i){
		line.push_back(i);
	}
}

void GetOutLine(vector<int>& line, vector<int>& worry, int n){
	int z = line.size();

	for (int i=z+n; i<z; ++i){
		Quiet(worry, i);
	}
	line.resize(z+n);
}

int WorryCount(vector<int>& worry){
	return worry.size();
}

int main(){

	vector<int> worry;
	vector<int> line;

	int q;
	cin >> q;

	string command;
	int n;
	int j = 0;
	while (j < q ){
		cin >> command;
		if (command != "WORRY_COUNT"){
			cin >> n;
		}
		else {
			cout << WorryCount(worry) << endl;
		}
		if (command == "COME"){
			if (n > 0){
				GetInLine(line, n);
			}
			else{
				GetOutLine(line, worry, n);
			}

		}
		if (command == "WORRY"){
			worry.push_back(n);
		}
		if (command == "QUIET"){
			Quiet(worry, n);
		}
		++j;
	}
//	8
//	COME 5
//	WORRY 1
//	WORRY 4
//	COME -2
//	WORRY_COUNT
//	COME 3
//	WORRY 3
//	WORRY_COUNT

	return 0;
}


