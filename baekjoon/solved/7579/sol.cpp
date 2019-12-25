#include <bits/stdc++.h>

using namespace std;

const int C = (int) 1e4;

int a[123];
int dp[C + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = C; j >= x; j--) {
      dp[j] = max(dp[j], dp[j - x] + a[i]);
    }
  }
  int ans = C;
  for (int i = 0; i <= C; i++) {
    if (dp[i] >= m) {
      ans = i;
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}
