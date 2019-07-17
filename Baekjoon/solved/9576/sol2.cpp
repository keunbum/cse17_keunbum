#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m);
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      a[x].push_back(y);
    }
    int ans = 0;
    multiset<int> s;
    for (int i = 0; i < m; i++) {
      for (int x : a[i]) {
        s.insert(x);
      }
      s.erase(i - 1);
      if (!s.empty()) {
        ans++;
        s.erase(s.begin());
      }
    }
    cout << ans << '\n';
  }
  return 0;
}