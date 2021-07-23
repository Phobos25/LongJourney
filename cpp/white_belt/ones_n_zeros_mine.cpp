
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> x;
	int n, ostatok;
    cin >> n;

	ostatok = n ;
	while (ostatok >= 2){
		x.push_back(ostatok%2);
		ostatok /= 2;
	}
	cout << 1;
	for (auto it = x.rbegin(); it != x.rend(); ++ it){
		cout << *it;
	}
	return 0;
}
