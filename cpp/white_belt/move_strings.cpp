#include <iostream>
#include <string>
#include <vector>
using namespace std;

// перемещает значения с source в destination и очищает source
void MoveStrings(vector <string>& source, vector <string>& destination){
	
	for (int i=0; i<source.size(); ++i){
		destination.push_back(source[i]);
	}
	source.clear();
}

int main() {
	vector <string> a = {"a", "b"};
	vector <string> b = {"c"};

	MoveStrings(a,b);

	for (int i=0; i < b.size(); ++i){
		cout << b[i] << ' ';
	}
	cout << endl;

	return 0;
}