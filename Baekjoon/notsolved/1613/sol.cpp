#include <bits/stdc++.h>

using namespace std;

const int N = 400;

int g[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  while (k--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    g[x][y] = 1;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      if (g[i][k]) {
        for (int j = 0; j < n; j++) {
          g[i][j] |= (g[i][k] & g[k][j]);
        }
      }
    }
  }
  int s;
  cin >> s;
  while (s--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << (g[y][x] - g[x][y]) << '\n';
  }
  return 0;
}
