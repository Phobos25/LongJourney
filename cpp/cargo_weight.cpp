#include <iostream>
#include <vector>

using namespace std;

unsigned int CalculateVolume(int a, int b, int c){
  return a*b*c;
}

int64_t CalculateMass(int v, int p){
  return p*v;
}

int main() {
  int n, p;
  int w, h, t;
  int64_t total_mass=0;
  cin >> n >> p;
  for (int i=0; i<n; ++i){
    cin >> w >> h >> t;
    total_mass += CalculateMass(CalculateVolume(w,h,t), p);
  }
  cout << total_mass << endl;
  return 0;
}



