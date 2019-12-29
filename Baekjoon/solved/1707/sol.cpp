#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e4;

int q[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    while (m--) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    bool ok = true;
    vector<int> c(n, -1);
    for (int i = 0; i < n; i++) {
      if (c[i] != -1) {
        continue;
      }
      int b = 0, e = 1;
      q[0] = i;
      c[i] = 0;
      while (b < e) {
        for (int u : g[q[b]]) {
          if (c[u] == -1) {
            c[u] = c[q[b]] ^ 1;
            q[e] = u;
            ++e;
          } else
          if (c[u] == c[q[b]]) {
            ok = false;
            break;
          }
        }
        if (!ok) {
          break;
        }
        ++b;
      }
      if (!ok) {
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
