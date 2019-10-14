#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int INF = (int) 1e9;
  int n;
  cin >> n;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
  vector<int> dist(n + 1, INF);
  dist[n] = 0;
  s.emplace(dist[n], n);
  vector<int> p(n + 1, -1);
  while (!s.empty()) {
    int i, expected;
    tie(expected, i) = s.top();
    s.pop();
    if (dist[i] != expected) {
      continue;
    }
    int u;
    if (i % 3 == 0) {
      u = i / 3;
      if (dist[u] > dist[i] + 1) {
        dist[u] = dist[i] + 1;
        s.emplace(dist[u], u);
        p[u] = i;
      }
    }
    if ((i & 1) == 0) {
      u = i >> 1;
      if (dist[u] > dist[i] + 1) {
        dist[u] = dist[i] + 1;
        s.emplace(dist[u], u);
        p[u] = i;
      }
    }
    if (i - 1 > 0) {
      u = i - 1;
      if (dist[u] > dist[i] + 1) {
        dist[u] = dist[i] + 1;
        s.emplace(dist[u], u);
        p[u] = i;
      }
    }
  }
  cout << dist[1] << '\n';
  vector<int> ans;
  int v = 1;
  while (v != n) {
    ans.push_back(v);
    v = p[v];
  }
  ans.push_back(n);
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < (int) ans.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}
