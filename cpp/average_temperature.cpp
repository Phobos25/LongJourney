#include <iostream>
#include <vector>
using namespace std;

int main (){
	int n;
	cin >> n;
	vector <int> temperatures(n);

	int sum = 0;
	for (int& t: temperatures){
		cin >> t;
		sum += t;
	}

	int avg = sum / n;

	vector <int> result_indices;

	for (int i=0; i<n; ++i){
		if (temperatures[i] > avg){
			result_indices.push_back (i);
		}
	}

	cout << result_indices.size() << endl;

	for (auto res: result_indices){
		cout << res << ' ';
	}

	return 0;
}