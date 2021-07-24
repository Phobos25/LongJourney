#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector <int>& numbers){
	vector <int> temp;
	for (int i=numbers.size()-1; i >= 0; --i){
		temp.push_back(numbers[i]);
	}
	numbers = temp;
}

int main() {
	vector <int> numbers = {1, 2, 3, 4, 5, 6, 7};

	Reverse(numbers);

	for (int i=0; i<numbers.size(); ++i){
		cout << numbers[i] << ' ';
	}
	cout << endl;

	return 0;
}