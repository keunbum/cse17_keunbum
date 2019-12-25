#include <iostream>

using namespace std;

bool v[501][501];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    v[a][b] = true;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (v[j][i]) {
        for (int k = 1; k <= n; k++) {
          v[j][k] |= v[j][i] & v[i][k];
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    bool ok = true;
    for (int j = 1; j <= n; j++) {
      if (j != i && !v[i][j] && !v[j][i]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
