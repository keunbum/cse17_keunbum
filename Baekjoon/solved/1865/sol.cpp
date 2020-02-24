#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, w;
    cin >> n >> m >> w;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m + w; i++) {
      int x, y, z;             	
      cin >> x >> y >> z;
      --x; --y;
      if (i < m) {
        edges.emplace_back(x, y, z);
        edges.emplace_back(y, x, z);
      } else {
        edges.emplace_back(x, y, -z);
      }
    }
    const int inf = (int) 1e9;
    bool neg_cycle = false;
    vector<int> was(n, false);
    for (int st = 0; st < n; st++) {
      if (was[st]) {
        continue;
      }
      was[st] = true;
      vector<int> dist(n, inf);
      dist[st] = 0;
      for (int i = 0; i < n; i++) {
        for (const auto& e : edges) {
          int x, y, z;
          tie(x, y, z) = e;
          if (dist[x] + z < dist[y]) {
            was[y] = true;
            dist[y] = dist[x] + z;
            if (i == n - 1) {
              neg_cycle = true;
              break;
            }
          }
        }
      }
      if (neg_cycle) {
        break;
      }
    }
    cout << (neg_cycle ? "YES" : "NO") << '\n';
  }
  return 0;
}
