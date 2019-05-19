#include <iostream>

using namespace std;

const int N = 16;
const int inf = (int) 1e9;

int n, bits, p;
int dis[N][N];
int dp[1 << N];
string run;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> dis[i][j];
    }
  }
  cin >> run >> p;
  for (int i = 0; i < n; i++) {
    if (run[i] == 'Y') bits |= (1 << i);
  }
  for (int t = 0; t < (1 << n); t++) {
    dp[t] = inf;
    if ((t | bits) == bits) dp[t] = 0;
  }
  int ans = inf;
  for (int t = 0; t < (1 << n); t++) {
    for (int j = 0; j < n; j++) {
      if (!(t & (1 << j))) continue;
      for (int i = 0; i < n; i++) {
        if (j == i || !(t & (1 << i))) continue;
        dp[t] = min(dp[t], dp[t ^ (1 << j)] + dis[i][j]);
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {   
      if (t & (1 << i)) cnt++;
    }
    if (cnt >= p) ans = min(ans, dp[t]);    
  }
  cout << (ans == inf ? -1 : ans) << '\n';
  return 0;
  }