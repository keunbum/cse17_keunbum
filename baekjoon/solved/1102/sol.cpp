#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
              
const int N = 16;
const int inf = (int) 1e9;

int n, p, bits;
int cost[N][N];
int dp[1 << N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  fill(dp, dp + (1 << n), -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> cost[i][j];
    }
  }
  string run;
  cin >> run >> p;
  int m = 0;
  for (int i = 0; i < n; i++) {
    if (run[i] == 'Y') {
      bits |= (1 << i);
      m++;
    }
  }
  function<int(int, int)> dfs = [&](int b, int c) {
    if (c >= p) return 0; // No additional cost
    int &ret = dp[b];
    if (ret != -1) return ret;
    ret = inf;
    for (int i = 0; i < n; i++) {
      if (!(b & (1 << i))) continue; // from powered
      for (int j = 0; j < n; j++) {
        if (b & (1 << j)) continue; // to not powered
        ret = min(ret, cost[i][j] + dfs(b | (1 << j), c + 1)); 
      }
    }
    return ret;
  };
  int ans = dfs(bits, m);
  cout << (ans == inf ? -1 : ans) << '\n';
  return 0;
}