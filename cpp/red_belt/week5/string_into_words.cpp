#include "profile.h"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<string> SplitIntoWords(const string& text){
    vector<string> words;
    string current_word;
    for (const char c:text){
        if (c == ' '){
            words.push_back(move(current_word));
            current_word.clear();
        } else {
            current_word.push_back(c);            
        }
    }

    words.push_back(move(current_word));
    return words;
}

int main() {

    vector<string> v;
    v = SplitIntoWords("two words");
    for (auto i: v){
        cout << i << "\n";
    }
    cout << "\n";
    return 0;   
}

    
