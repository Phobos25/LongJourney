#include "sum_reverse_sort.h"

int Sum(int x, int y);
string Reverse(string s);
void Sort(vector<int>& nums);

int Sum(int x, int y) {
    return x + y;
}

string Reverse(string s){
    string reversed_s = "";    
	for (size_t i=s.length(); i >= 0; --i){
		reversed_s += s[i];
	}
	return reversed_s;
}

void Sort(vector<int>& nums){
    for (size_t idx_i = 0; idx_i + 1 < nums.size(); ++idx_i) {
    for (size_t idx_j = 0; idx_j + 1 < nums.size() - idx_i; ++idx_j) {
      if (nums[idx_j + 1] < nums[idx_j]) {
        swap(nums[idx_j], nums[idx_j + 1]);
      }
    }
  }
}
#include "sum_reverse_sort.h"

int Sum(int x, int y);
string Reverse(string s);
void Sort(vector<int>& nums);

int Sum(int x, int y) {
    return x + y;
}

string Reverse(string s){
    string reversed_s = "";
    for (int i=s.length()-1; i >= 0; --i){
        reversed_s += s[i];
    }
    return reversed_s;
}

void Sort(vector<int>& nums){
    for (size_t idx_i = 0; idx_i + 1 < nums.size(); ++idx_i) {
    for (size_t idx_j = 0; idx_j + 1 < nums.size() - idx_i; ++idx_j) {
      if (nums[idx_j + 1] < nums[idx_j]) {
        int temp = nums[idx_j];
        nums[idx_j] = nums[idx_j + 1];
        nums[idx_j + 1] = temp;
      }
    }
  }
}
