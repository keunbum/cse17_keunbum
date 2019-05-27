#include <iostream>
#include <algorithm>

using namespace std;

bool prime[1234];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fill_n(prime, 1234, true);
  int n, k;
  cin >> n >> k;
  for (int i = 2; i <= n; i++) {
    if (!prime[i]) continue;
    if (--k == 0) { cout << i << '\n'; return 0; }
    for (int j = 2 * i; j <= n; j += i) {
      if (!prime[j]) continue;
      prime[j] = false;
      if (--k == 0) { cout << j << '\n'; return 0; }
    }
  }
  return 0;
}