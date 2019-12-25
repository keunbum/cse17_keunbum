#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>

using namespace std;

vector<int> old;

struct cmp {
  bool operator()(int i, int j) {
    return old[i] > old[j];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    old.clear();
    old.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      int t;
      cin >> t;
      old[t] = i;
    }
    int m;
    cin >> m;
    vector<int> deg(n + 1, 0);
    vector<vector<int>> g(n + 1);
    vector<vector<bool>> swapped(n + 1, vector<bool>(n + 1, false));
    while (m--) {
      int x, y;
      cin >> x >> y;
      swapped[x][y] = swapped[y][x] = true;
      if (old[x] < old[y]) swap(x, y);
      g[x].push_back(y);
      deg[y]++;
    }
    priority_queue<int, vector<int>, cmp> s;
    for (int i = 1; i <= n; i++) {
      if (deg[i] == 0) {
        s.push(i);
      }
    }
    vector<int> ans, now(n + 1);
    int cnt = 0;
    while (!s.empty()) {
      int v = s.top();
      s.pop();
      ans.push_back(v);
      now[v] = ++cnt;
      for (int to : g[v]) {
        if (--deg[to] == 0) {
          s.push(to);
        }
      }
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if ((old[i] < old[j]) ^ (now[i] > now[j])) continue;
        if (!swapped[i][j]) {
          ok = false;
          j = i = n;
        }
      }
    }
    if (ok) {
      for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' ';
        cout << ans[i];
      }
      cout << '\n';
    }
    else cout << "IMPOSSIBLE" << '\n';
  }
  return 0;
}