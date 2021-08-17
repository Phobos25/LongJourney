#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct Users{
  int id;
  int pages;  
  Users (int i, int p){
    id = i;
    pages = p;
  }
};

bool operator < (const Users& lhs, const Users& rhs){
  return lhs.pages < rhs.pages;
}

int main() {
  vector<Users> users;
  Users user1(1, 5);
  Users user2(2, 3);
  users.push_back(user1);
  users.push_back(user2);
  users.push_back(Users(3, 7));
  users.push_back(Users(4, 10));
  users.push_back(Users(5, 1));  
  
  
  return 0;
}