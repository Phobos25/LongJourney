#include <iostream>
#include <vector>
using namespace std;


void add_worry(vector<int>& worry, int i){
	worry.push_back(i);
}

int main(){

	int q;
	cin >> q;
	string command;
	int n;
	cin >> command >> n;

	cout << command <<endl << n;

	return 0;
}