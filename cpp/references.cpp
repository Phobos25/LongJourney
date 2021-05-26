#include <iostream>
#include <string>
#include <vector>
using namespace std;

void UpdateIfGreater(int first, int& second){
	if (second < first){
		second = first;
	}
}

int main() {
	int a, b;
	cin >> a >> b;
	UpdateIfGreater(5,b);
	cout << a << ' ' <<b << endl;

	return 0;
}