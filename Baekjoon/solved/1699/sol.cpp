#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int a[123456];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    a[i] = i;
    int j = (int) sqrt(i);
    for ( ; j >= 1; j--) {
      a[i] = min(a[i], a[i - j * j] + 1);
    }
  }
  cout << a[n] << '\n';
//cerr << (float)clock() / CLOCKS_PER_SEC << " seconds" << '\n';
  return 0;
}