#include <bits/stdc++.h>

using namespace std;

const int MD = (int) 1e9;

inline void Add(int &a, int b) {
  a += b;
  if (a >= MD) a -= MD;
}

int dp[1 << 10][101][10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 1; i < 10; i++) {
    dp[1 << i][1][i] = 1;
  }
  for (int i = 2; i <= 100; i++) {
    for (int j = 0; j < 10; j++) {
      for (int t = 1; t < (1 << 10); t++) {
        if (j - 1 >= 0 && (t & (1 << (j - 1)))) {
          Add(dp[t | (1 << j)][i][j], dp[t][i - 1][j - 1]);
        }
        if (j + 1 < 10 && (t & (1 << (j + 1)))) {
          Add(dp[t | (1 << j)][i][j], dp[t][i - 1][j + 1]);
        }
      }
    }
  }
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < 10; i++) {
    Add(ans, dp[(1 << 10) - 1][n][i]);
  }
  cout << ans << '\n';
  return 0;
}
