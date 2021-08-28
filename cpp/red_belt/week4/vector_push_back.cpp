#include "profile.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size;
    cin >> size;

    { LOG_DURATION ("push_back")
      vector<int> v;
      for (int i=0; i< size; ++i)  {
          v.push_back(i);
      }
    }
    { LOG_DURATION ("push_back_better")
      vector<int> v;
      v.reserve(size);
      for (int i=0; i< size; ++i)  {
          v.push_back(i);
      }
    }
    return 0;
}