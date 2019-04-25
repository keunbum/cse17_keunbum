#include <iostream>

using namespace std;

int a[123][123];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int b, s;
    cin >> b >> s;
    a[b][s] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[j][i]) {
        for (int k = 1; k <= n; k++) {
          a[j][k] |= a[j][i] & a[i][k];
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      cnt += i == j || (a[i][j] || a[j][i]);
    }
    cout << n - cnt << '\n';
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
