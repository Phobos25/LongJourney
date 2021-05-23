
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> x;
	int n, ostatok;
    cin >> n;

	ostatok = n ;
	while (ostatok > 2){
		x.push_back(ostatok%2);
		ostatok /= 2;
	}

	if (n <= 2) {
		if (n == 1){
			cout << 1;
		}
		else {
			cout << 10;
		}
	}
	else {
		cout << 1;
		for (int i=x.size(); i>=0; --i){
			cout << x[i];
		}
	}

	return 0;
}
