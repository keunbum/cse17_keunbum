#include <iostream>

using namespace std;

unsigned long long zero[91], one[91];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  zero[0] = one[0] = 0;
  zero[1] = 0;
  one[1] = 1;
  for (int i = 2; i < 91; i++) {
    zero[i] = zero[i - 1] + one[i - 1];
    one[i] = zero[i - 1];
  }
  cout << zero[n] + one[n] << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
