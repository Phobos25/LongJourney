#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	set <int> s = {1, 2, 3};
	int x = 4;
	s.erase(x);
	s.insert(x);

	cout << s.size();
}
