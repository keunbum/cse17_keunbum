#include <iostream>

using namespace std;

const int N = 1000;

int a[N + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  a[0] = 1;
  a[1] = a[0];
  for (int i = 2; i <= n; i++) {
    a[i] = (a[i - 1] + a[i - 2] * 2) % 10007;
  }
  cout << a[n] << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
