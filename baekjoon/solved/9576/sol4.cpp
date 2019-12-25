#include <iostream>
#include <vector>
#include <queue>

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
    priority_queue<int, vector<int>, greater<int>> s;
    int ans = 0;
    for (int i = 0; i < m; i++) {
      for (int x : a[i]) s.push(x);
      while (!s.empty() && s.top() < i) s.pop();
      if (!s.empty()) {
        ans++;
        s.pop();
      }
    }
    cout << ans << '\n';
  }
  return 0;
}