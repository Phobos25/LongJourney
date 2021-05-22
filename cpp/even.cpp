/*
 * even.cpp
 *
 *  Created on: May 22, 2021
 */
#include <iostream>
using namespace std;

int main(){
	int a, b, x;
	cin >> a >> b;

	for(int i=a; i<=b; ++i){
		if (i % 2 == 0){
			cout << i << " ";
		}
	}
}

