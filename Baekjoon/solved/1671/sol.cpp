#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class st {
public:
  int x, y, z;
  bool operator<(st &o) {
    return x <= o.x && y <= o.y && z <= o.z;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<st> a;
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    a.push_back({x, y, z});
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && a[j] < a[i]) {
        if (a[i] < a[j] && i < j) continue;
        g[i].push_back(j);
      }
    }
  }
  vector<vector<int>> pa(n, vector<int>(2, -1));
  vector<int> pb(n, -1), was(n, 0);
  int iter = 0;
  function<bool(int, int)> dfs = [&](int v, int k) {
    was[v] = iter;
    for (int u : g[v]) {
      if (pb[u] == -1) {
        pa[v][k] = u;
        pb[u] = v;
        return true;
      }
    }
    for (int u : g[v]) {
      if (was[pb[u]] != iter && (dfs(pb[u], 0) || dfs(pb[u], 1))) {
        pa[v][k] = u;
        pb[u] = v;
        return true;
      }
    }
    return false;
  };
  int ans = 0;
  while (true) {
    iter++;
    int add = 0;
    for (int i = 0; i < n; i++) {
      if (pa[i][0] == -1) add += (int) dfs(i, 0);
      if (pa[i][1] == -1) add += (int) dfs(i, 1);
    }
    if (add == 0) break;
    ans += add;
  }
  cout << n - ans << '\n';
  return 0;
}