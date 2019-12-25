#include <iostream>
#include <algorithm>

using namespace std;

int dp[12345];

const int inf = (int) 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {                 
    dp[i] = inf;                                 
  }
  while (n--) {
    int a;
    cin >> a;
    for (int i = a; i <= k; i++) {
      dp[i] = min(dp[i], dp[i - a] + 1);
    }
  }
  cout << (dp[k] == inf ? -1 : dp[k]) << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
