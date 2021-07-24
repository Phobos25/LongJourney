/*
 * palindromFilter.cpp
 *
 *  Created on: May 25, 2021
 */
#include <iostream>
#include <vector>
using namespace std;

bool IsPalindrom(string s) {
    // Замечание: более правильным было бы использовать здесь тип size_t вместо int
    // О причинах Вы узнаете на Жёлтом поясе
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

vector <string> PalindromFilter(vector <string> words, int minLength){
	vector <string> result;
	for (string word: words){
		if (word.size() >= minLength){
			if (IsPalindrom(word)){
				result.push_back(word);
			}
		}
	}
	return result;
}

int main(){
	vector <string> vec_a = {"argentinamanitnegra", "animalassalamina",
			"weew", "bro", "code"};
	vector <string> vec_out;
	int b = 4;

	vec_out = PalindromFilter(vec_a, b);

	for (int i=0; i<vec_out.size(); ++i){
		cout << vec_out[i] << endl;
	}
	return 0;
}

