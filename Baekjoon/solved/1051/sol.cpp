#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = 0; ; k++) {
        int s = j - i;
        if (k + s >= m) {
          break;
        }
        char x = a[i][k];
        char y = a[i][k + s];
        char z = a[j][k];
        char w = a[j][k + s];
        if (x == y && y == z && z == w) {
          ans = max(ans, (s + 1) * (s + 1));
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
