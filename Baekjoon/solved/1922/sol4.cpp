#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int x, y, z;
  Edge(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
  bool operator<(const Edge &o) const {
    return z > o.z;
  }
};

vector<int> p;

int get(int x) {
  return x == p[x] ? x : (p[x] = get(p[x]));
}

bool unite(int a, int b) {
  a = get(a);
  b = get(b);
  if (a == b) return false;
  p[a] = b;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  p.resize(n);
  iota(p.begin(), p.end(), 0);
  priority_queue<Edge> s;
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    s.emplace(x, y, z);
  }
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    Edge e{0, 0, 0};
    do {
      e = s.top();
      s.pop();
    } while (!unite(e.x, e.y));
    ans += e.z;
  }
  cout << ans << '\n';
  return 0;
}