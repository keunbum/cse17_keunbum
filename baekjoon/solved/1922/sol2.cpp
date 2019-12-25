#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <tuple>

using namespace std;

vector<int> p;
vector<tuple<int, int, int>> e;

int get(int x) {
  return (x == p[x]) ? x : (p[x] = get(p[x]));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  p.resize(n);
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    e.emplace_back(z, x, y);
  }
  sort(e.begin(), e.end());
  iota(p.begin(), p.end(), 0);
  int ans = 0;
  m = (int) e.size();
  for (int i = 0; i < m; i++) {
    int u = get<1>(e[i]);
    int v = get<2>(e[i]);
    u = get(u);
    v = get(v);
    if (u == v) continue;
    p[u] = v;
    ans += get<0>(e[i]);
  }
  cout << ans << '\n';
  return 0;
}