#include <iostream>
#include <queue>
using namespace std;

int main2() {

queue<int*> theQueue;
char c = 'n';

while (c == 'n') {
  cout << "Enter \'n\' to add a new number to queue ( \'q\' to quit):";
  cin >> c;
  if ( c == 'q') {
    break;
  }
  else {
    int num;
    cout << "Enter an integer and press return: ";
    cin >> num;
    int* ptr = new int(num);
    theQueue.push(ptr);
  }
}

while( !theQueue.empty() ) {
  cout << theQueue.front() << ": " << *theQueue.front() << endl;
      delete theQueue.front();
  theQueue.pop();
}
return 0;
}