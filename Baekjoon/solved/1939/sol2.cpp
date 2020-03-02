#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> edges;
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    edges.emplace_back(x, y, z);
  }
  sort(edges.begin(), edges.end(), [&](const auto& ei, const auto& ej) {
    return get<2>(ei) > get<2>(ej);
  });
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  function<int(int)> Get = [&](int v) {
    return v == p[v] ? v : (p[v] = Get(p[v]));
  };
  int st, en;
  cin >> st >> en;
  --st; --en;
  for (const auto& e : edges) {
    int x, y, z;
    tie(x, y, z) = e;
    x = Get(x);
    y = Get(y);
    p[x] = y;
    if (Get(st) == Get(en)) {
      cout << z << '\n';
      break;
    }
  }
  return 0;
}
