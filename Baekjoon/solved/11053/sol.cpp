#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1234][1234];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b.begin(), b.end());
  for (int i = 1; i < (int) b.size(); ) {
    if (b[i] == b[i - 1]) {
      b.erase(b.begin() + i);
    } else i++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= (int) b.size(); j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  cout << dp[n][b.size()] << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}