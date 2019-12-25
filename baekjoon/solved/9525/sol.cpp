#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<string> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int n = 0;
  vector<vector<int>> b(N, vector<int>(N, -1));
  for (int i = 0; i < N; i++) {
    int j = 0;
    while (true) {
      while (j < N && a[i][j] == 'X') j++;
      if (j == N) break;
      while (j < N && a[i][j] == '.') {
        b[i][j++] = n;
      }
      n++;
      if (j == N) break;
    }
  }
  int m = 0;
  vector<vector<int>> c(N, vector<int>(N, -1));
  for (int i = 0; i < N; i++) {
    int j = 0;
    while (true) {
      while (j < N && a[j][i] == 'X') j++;
      if (j == N) break;
      while (j < N && a[j][i] == '.') {
        c[j++][i] = m;
      }
      m++;
      if (j == N) break;
    }
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (a[i][j] == '.') {
        g[b[i][j]].push_back(c[i][j]);
      }
    }
  }
  vector<int> pa(n, -1), pb(m, -1), was(n, 0);
  int iter = 0;
  function<bool(int)> dfs = [&](int v) {
    was[v] = iter;
    for (int u : g[v]) {
      if (pb[u] == -1) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    for (int u : g[v]) {
      if (was[pb[u]] != iter && dfs(pb[u])) {
        pa[v] = u;
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
      if (pa[i] == -1) {
        add += (int) dfs(i);
      }
    }
    if (add == 0) {
      break;
    }
    ans += add;
  }
  cout << ans << '\n';
  return 0;
}