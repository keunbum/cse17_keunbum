#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    vector<int> a;
    while (true) {
      int t;
      cin >> t;
      if (t == -1) return 0;
      if (t == 0) break;
      a.push_back(t);
    }
    int ans = 0;
    int n = (int) a.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ans += (int) (a[i] * 2 == a[j]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
