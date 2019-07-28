#include <iostream>
#include <cmath>

using namespace std;

int f[123456];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    f[i] = i;
    for (int j = (int) sqrt(i); j >= 1; j--) {
      f[i] = min(f[i], f[i - j * j] + 1);
    }
  }
  cout << f[n] << '\n';
  return 0;
}