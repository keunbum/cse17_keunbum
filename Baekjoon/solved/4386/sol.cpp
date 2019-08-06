#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

struct edge {
  int from, to;
  double cost;
  bool operator<(const edge &o) {
    return cost < o.cost;
  }
};

vector<int> p;
vector<edge> edges;

int get(int x) {
  return x == p[x] ? x : p[x] = get(p[x]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(2);
  cout << fixed;
  int n;
  cin >> n;
  vector<pair<double, double>> a;
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    a.emplace_back(x, y);
  }
  p.resize(n);
  iota(p.begin(), p.end(), 0);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double u = a[i].first - a[j].first;
      double v = a[i].second - a[j].second;
      double cost = sqrt(u * u + v * v);
      edges.push_back({i, j, cost});
    }
  }
  sort(edges.begin(), edges.end());
  double ans = 0.0;
  for (const edge &e : edges) {
    int X = get(e.from);
    int Y = get(e.to);
    if (X != Y) {
      p[X] = Y;
      ans += e.cost;
    }
  }
  cout << ans << '\n';
  return 0;
}