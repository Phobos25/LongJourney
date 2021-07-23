#include <iostream>
#include <string>
using namespace std;

int main(){
	/*string a = "milk";
	string b = "milkshake";
	string c = "month";
*/
	string a, b, c;
	string result = "";
	cin >> a >> b >> c;

	if (a <= b){ 
		if (a <= c){
			result = a;
			} 
	}
	if (b <= a){
		if (b<= c){	
			result = b;
			}
	}
	if (c <= b){
		if (c <= a){
			result = c;
			}
	}
	cout << result;
	return 0;
}