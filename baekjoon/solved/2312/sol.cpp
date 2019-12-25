#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool nprime[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  nprime[1] = true;
  for (int i = 2; i < 100001; i++) {
    if (nprime[i]) continue;
    for (int j = 2 * i; j < 100001; j += i) {
      nprime[j] = true;
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (int p = 2; p <= n; p++) {
      if (nprime[p]) continue;
      int cnt = 0;
      while (n % p == 0) {
        n /= p;
        cnt++;
      }
      if (cnt) cout << p << ' ' << cnt << '\n';
    }
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
