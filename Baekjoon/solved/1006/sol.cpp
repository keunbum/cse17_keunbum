#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, w;
    cin >> n >> w;
    vector<int> a(n + n);
    for (int i = 0; i < n + n; i++) {
      cin >> a[i];
    }
    const int D[4] = {-1, 1, -n, n};
    auto I = [&](int i, int dir) {
      int j;
      int S = (i / n) * n;
      int E = S + n;
      if (dir < 2) {
        j = i + D[dir];
        if (j < S) j = E - 1; else
        if (j >= E) j = S;
      } else {
        j = i + D[2];
        if (j < 0) j = i + D[3];
      }
      return j;
    };
    vector<vector<int>> g(n + n);
    for (int i = 0; i < n + n; i++) {
      for (int dir = 0; dir < 3; dir++) {
        int j = I(i, dir);
        if (a[i] + a[j] <= w && i != j) {
          g[i].push_back(j);
        }
      }
    }
    vector<int> pa(n + n, -1);
    vector<int> pb(n + n, -1);
    vector<int> was(n + n, 0);
    int iter = 0;
    function<bool(int)> Dfs = [&](int v) {
      was[v] = iter;
      for (int u : g[v]) {
        if (pb[u] == -1) {
          pa[v] = u;
          pb[u] = v;
          return true;
        }
      }
      for (int u : g[v]) {
        if (was[pb[u]] != iter && Dfs(pb[u])) {
          pa[v] = u;
          pb[u] = v;
          return true;
        }
      }
      return false;
    };
    int match = 0;
    while (true) {
      ++iter;
      int cnt = 0;
      for (int i = 0; i < n + n; i++) {
        cnt += (int) (pa[i] == -1 && Dfs(i));
      }
      if (cnt == 0) break;
      match += cnt;
    }
    int ans = n + n - match / 2;
    cout << ans << '\n';
//    cerr << (double) clock() / CLOCKS_PER_SEC << " s\n"; 
  }
  return 0;
}
