#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

struct edge {
  int from, to;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n == 0) break;
    vector<edge> edges;
    vector<int> r, b;
    while (m--) {
      char x;
      int y, z;
      cin >> x >> y >> z;
      int id = (int) edges.size();
      if (x == 'R') {
        r.push_back(id);
      } else {
        b.push_back(id);
      }
      edges.push_back({ y, z });
    }
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    function<int(int)> get = [&](int v) { return v == p[v] ? v : p[v] = get(p[v]); };
    for (int id : r) {
      const edge &e = edges[id];
      int X = get(e.from), Y = get(e.to);
      if (X != Y) { p[Y] = X; }
    }
    vector<int> B;
    for (int id : b) {
      const edge &e = edges[id];
      int X = get(e.from), Y = get(e.to);
      if (X != Y) {
        p[Y] = X;
        B.push_back(id);
      }
    }
    iota(p.begin(), p.end(), 0);
    int blues = 0;
    for (int id : B) {
      const edge &e = edges[id];
      int X = get(e.from), Y = get(e.to);
      if (X != Y) {
        p[Y] = X;
        blues++;
      }
    }
    for (int id : b) {
      const edge &e = edges[id];
      if (blues >= k) break;
      int X = get(e.from), Y = get(e.to);
      if (X != Y) {
        p[Y] = X;
        blues++;
      }
    }
    int reds = 0;
    for (int id : r) {
      const edge &e = edges[id];
      int X = get(e.from), Y = get(e.to);
      if (X != Y) {
        p[Y] = X;
        reds++;
      }
    }
    cout << ((int) (reds + k == n - 1 && k == blues)) << '\n';  
  }
  return 0;
}