#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[1234567];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x > y) {
      swap(x, y);
    }
    a[i] = {x, y};
  }
  sort(a, a + n);
  int mn = a[0].first;
  int mx = a[0].second;
  int p = 1;
  int ans = 0;
  while (true) {
    while (p < n && a[p].first <= mx) {
      mx = max(mx, a[p].second);
      p++;
    }
    ans += mx - mn;
    if (p == n) {
      break;
    }
    mn = a[p].first;
    mx = a[p].second;
  }
  cout << ans << '\n';
  return 0;
}
