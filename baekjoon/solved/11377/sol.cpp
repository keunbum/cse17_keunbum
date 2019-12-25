/* impossible.. */
#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int iter, ans;
vector<vector<int>> g, pa;
vector<int> pb, was;

bool dfs(int v, int w) {
  if (w && k <= 0) return false;
  was[v] = iter;
  for (int u : g[v]) {
    if (pb[u] == -1) {
      pa[v][w] = u;
      pb[u] = v;
      if (w) k--;
      return true;
    }
  }
  for (int u : g[v]) {
    if (was[pb[u]] != iter) {
      if (dfs(pb[u], 0) || dfs(pb[u], 1)) {
        pa[v][w] = u;
        pb[u] = v;
        return true;
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  g.resize(n);
  pa.resize(n, vector<int>(2, -1));
  pb.resize(m, -1);
  was.resize(n, 0);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    while (t--) {
      int j;
      cin >> j;
      g[i].push_back(j - 1);
    }
  }
  iter = 0; ans = 0;
  while (true) {
    iter++;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (pa[i][0] == -1) cnt += (int) dfs(i, 0);
      if (pa[i][1] == -1) cnt += (int) dfs(i, 1);
    }
    if (cnt == 0) {
      break;
    }
    ans += cnt;
  }
  cout << ans << '\n';
  return 0;
}