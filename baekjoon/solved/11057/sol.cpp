#include <iostream>

using namespace std;

const int mod = 10007;
int dp[1234][10];

inline int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 10; i++) {
    dp[1][i] = 1;
  }
  for (int i = 2; i < 1001; i++) {
    dp[i][0] = dp[i - 1][0];
    for (int j = 1; j < 10; j++) {             
      dp[i][j] = add(dp[i][j - 1], dp[i - 1][j]);
    } 
  }
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < 10; i++) {
    ans = add(ans, dp[n][i]);
  }
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}