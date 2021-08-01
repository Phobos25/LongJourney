#include <string>
#include <vector>
using namespace std;

#define UNIQ_HELPER(x) var_##x
#define UNIQ(x) UNIQ_HELPER(x)
#define UNIQ_ID UNIQ(__LINE__)

int main() {
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};
}
