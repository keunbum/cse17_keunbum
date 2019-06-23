#include <iostream>

using namespace std;

const int N = 567;

int a[N][N], dp[N][N];

int hi(int x, int y) {
  if (dp[x][y] >= 0) {
    return dp[x][y];
  }
  int res = 0;
  for (int i = 0; i < 4; i++) {
    int u = x + "2101"[i] - '1';
    int v = y + "1210"[i] - '1';
    if (a[u][v] > a[x][y]) {
      res += hi(u, v);
    }
  }
  return dp[x][y] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  fill_n(dp[0], N * N, -1);
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }
  dp[1][1] = 1;
  cout << hi(h, w) << '\n';
  return 0;
}