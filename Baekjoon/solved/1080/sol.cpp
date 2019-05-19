#include <iostream>

using namespace std;

int a[50][50], b[50][50];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c; cin >> c;
      a[i][j] = c - '0';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c; cin >> c;
      b[i][j] = c - '0';
    }
  }
  int ans = 0;
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < m - 2; j++) {
      if (a[i][j] ^ b[i][j]) {
        ans++;
        for (int x = 0; x < 3; x++) {
          for (int y = 0; y < 3; y++) {
            a[i + x][j + y] ^= 1;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] ^ b[i][j]) { cout << -1 << '\n'; return 0; }
    }
  }
  cout << ans << '\n';
  return 0;
}