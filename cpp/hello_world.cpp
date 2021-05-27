#include <iostream>
#include <string>
using namespace std;

int main(){
	/*string a = "milk";
	string b = "milkshake";
	string c = "month";
*/
	string a, b, c;
	cin >> a >> b >> c;
	if (a <= b){
		if (a <= c){
			cout << a;
		} 
	} 

	if (b < a){
		if (b< c){
			cout << b;
		}
	}

	if (c < b){
		if (c < a){
			cout << c;
		}
	}

	return 0;
}