#include <iostream>
#include <vector>
using namespace std;

vector <int> Reversed(const vector <int>& numbers){
	vector <int> temp;
	for (int i=numbers.size()-1; i >= 0; --i){
		temp.push_back(numbers[i]);
	}
	return temp;
}

int main() {
	vector <int> numbers = {1, 2, 3, 4, 5, 6, 7};

	vector <int> temp; 
	temp = Reversed(numbers);

	for (int i=0; i<temp.size(); ++i){
		cout << temp[i] << ' ';
	}
	cout << endl;

	return 0;
}