#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> b(m);
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int ans = n + m;
  int p_a = 0;
  int p_b = 0;
  while (p_a < n && p_b < m) {
    if (a[p_a] == b[p_b]) {
      ans -= 2;
      ++p_a;
      ++p_b;
    } else
    if (a[p_a] < b[p_b]) {
      ++p_a;
    } else {
      ++p_b;
    }
  }
  cout << ans << '\n';
  return 0;
}
