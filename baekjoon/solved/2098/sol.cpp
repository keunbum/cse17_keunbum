#include <iostream>
#include <algorithm>

using namespace std;

const int N = 16;
const int inf = (int) 1e9;

int adj[N][N], dp[N][1 << N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  fill_n(dp[0], N * (1 << N), inf);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> adj[i][j];
      if (adj[i][j] == 0) adj[i][j] = inf;
    }
  }
  for (int i = 1; i < n; i++) {
    dp[i][1 << i] = adj[0][i];
  }
  for (int t = 0; t < (1 << n); t++) {
    for (int i = 0; i < n; i++) {
      if ((t & (1 << i)) == 0) continue;
      for (int j = 0; j < n; j++) {
        if ((t & (1 << j)) == 0) continue;
        dp[i][t] = min(dp[i][t], dp[j][t ^ (1 << i)] + adj[j][i]);
      }
    }
  }
  cout << dp[0][(1 << n) - 1] << '\n';
  return 0;
}