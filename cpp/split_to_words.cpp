#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> SplitIntoWords(const string& s){
    vector<string> v;
    string temp = s;
    int start = 0;
    int end = temp.find(" ");
    while (end != -1){
        v.push_back(temp.substr(start, end-start));
        start = end + 1;
        end = temp.find(" ", start);
    }
    v.push_back(temp.substr(start, s.size()));
    return v;  
}

int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
            cout << *it;
        }
    cout << endl;
    return 0;
}

