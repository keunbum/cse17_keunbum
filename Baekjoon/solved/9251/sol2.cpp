#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1234][1234];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  int l1 = a.length(), l2 = b.length();
  for (int i = 1; i <= l1; i++) {
    for (int j = 1; j <= l2; j++) {
      if (a[i - 1] == b[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    }
  }
  cout << dp[l1][l2] << '\n';
  return 0;
}
