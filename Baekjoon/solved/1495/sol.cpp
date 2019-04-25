#include <iostream>

using namespace std;

bool dp[123][1234];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, s, M;
  cin >> n >> s >> M;
  dp[0][s] = true;
  for (int i = 1; i <= n; i++) {
    int v;
    cin >> v;
    for (int j = 0; j <= M; j++) {
      if (!dp[i - 1][j]) continue;
      if (j - v >= 0) dp[i][j - v] |= true;
      if (j + v <= M) dp[i][j + v] |= true;
    }
  }
  for (int i = M; i >= 0; i--) {
    if (dp[n][i]) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}