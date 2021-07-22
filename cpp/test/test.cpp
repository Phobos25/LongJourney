#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string Trim(const std::string& line)
{
    const char* WhiteSpace = " \t";
    size_t start = line.find_first_not_of(WhiteSpace);
    size_t end = line.size();
    return start == end ? std::string() : line.substr(start, end - start + 1);
}

string ParseEvent(istream& is) {  
  string str;
  getline(is, str);  
  return Trim(str);
}

int main(){  
  
  cout << ParseEvent(cin)<< endl;
  return 0;
}