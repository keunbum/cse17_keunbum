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
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> adj[i][j];
      if (adj[i][j] == 0) adj[i][j] = inf;
    }
  }
  fill_n(dp[0], N * (1 << N), inf);
  dp[0][1] = 0;
  for (int t = 1; t < (1 << n); t++) {
    for (int i = 0; i < n; i++) {
      if (dp[i][t] == inf) continue;
      for (int j = 0; j < n; j++) {
        if ((t | (1 << j)) == t) continue;
        dp[j][t | (1 << j)] = min(dp[j][t | (1 << j)], dp[i][t] + adj[j][i]);
      }
    }
  }
  int ans = inf;
  for (int i = 1; i < n; i++) {
    ans = min(ans, dp[i][(1 << n) - 1] + adj[0][i]);
  }
  cout << ans << '\n';
  return 0;
}