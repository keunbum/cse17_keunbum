#include <iostream>
#include <vector>

using namespace std;

const int N = 500;

int a[N + 1], dp[N + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a[x] = y;
  }
  vector<int> v;
  for (int i = 1; i <= N; i++) {
    if (a[i]) {
      v.push_back(a[i]);
    }
  }
  int m = (int) v.size();
  int mx = 1;
  for (int i = 0; i < m; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (v[j] < v[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    mx = max(mx, dp[i]);
  }
  cout << n - mx << '\n';
  return 0;
}