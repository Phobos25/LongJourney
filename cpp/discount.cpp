/*
 * discount.cpp
 *
 *  Created on: May 22, 2021
 *Написать программу вычисления стоимости покупки товара с учётом скидки.
 *Если исходная стоимость товара больше A рублей, то на неё
 *устанавливается скидка в X процентов. Если исходная
 *стоимость товара больше B рублей, то на неё устанавливается
 *скидка в Y процентов.
 *На вход программе даны пять вещественных чисел: N, A, B, X, Y
 *(A < B) - где N - исходная стоимость товара. Выведите
 *стоимость покупки товара с учётом скидки.
 */

#include <iostream>
using namespace std;

int main(){
	/*
	 * 100 110 120 5 10
	 * 115 110 120 5 10
	 * 150 110 120 5 12.5
	 */

	double n, a, b, x, y;

	cin >> n >> a >> b >> x >> y;

	if (n>b){
		n *= 1-y/100;
	}
	else if (n>a){
		n *= 1-x/100;
	}

	cout << n;

	return 0;
}

