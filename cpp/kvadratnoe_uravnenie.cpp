#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	double A, B, C;
	double D, x1,x2;

	cin >> A >> B >> C;
	
	//если это не квадратное уравнение
	if (A == 0) {
		if (B == 0){
			cout << ' ';
			return 0;
		}else {
			x1 = -C/B;
			cout << x1;
			return 0;	
		}
		
	}

	//решение квадратного уравнения

	D = B*B - 4*A*C;

	if (D < 0){
		//корней у уравнения нет
		cout << ' ';
		return 0;
	}
	if (D == 0){
		//уравнение имеет 1 корень
		x1 = -B/2/A;
		cout << x1;
		return 0;
	}

	x1 = (-B + sqrt(D))/2/A;
	x2 = (-B - sqrt(D))/2/A;
	cout << x1 << ' ' << x2;
	return 0;
}