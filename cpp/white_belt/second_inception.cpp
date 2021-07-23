#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	int count = 0;
	cin >> a;

	for (int i=0; i < a.size(); ++i){
		if (a[i] =='f'){
			if (count >= 1){
				cout << i << endl;
				count += 1;
				break;
			}
			else {
				count += 1;
			}
		}
	}
	if (count != 2){
		if (count == 1){
			cout << -1 << endl;
		}
		else {
			cout << -2 << endl;
		}
	}
	return 0;
}
