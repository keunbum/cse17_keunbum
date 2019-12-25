#include <bits/stdc++.h>

using namespace std;

struct Point {
  int x;
  int y;
  bool operator<(const Point& o) const {
    if (y != o.y) {
      return y < o.y;
    }
    return x < o.x;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX_X = (int) 1e4;
  int n;
  cin >> n;
  vector<Point> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  sort(a.begin(), a.end(), [&](const Point& p, const Point& q) {
    return p.x < q.x;
  });
  set<Point> s = {a[0], a[1]};
  auto Dis = [&](const Point& p, const Point& q) {
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
  };
  int ans = Dis(a[0], a[1]);
  int st = 0;
  for (int i = 2; i < n; i++) {
    Point cur = a[i];
    while (st < i) {
      int dx = cur.x - a[st].x;
      if (dx * dx <= ans) {
        break;
      }
      s.erase(a[st]);
      st++;
    }
    int dr = (int) sqrt((double) ans) + 1;
    auto low = s.lower_bound({-MAX_X, cur.y - dr});
    auto up = s.upper_bound({MAX_X, cur.y + dr});
    for (auto it = low; it != up; it++) {
      int dist = Dis(cur, *it);
      if (dist < ans) {
        ans = dist;
      }
    }
    s.insert(cur);
  }
  cout << ans << '\n';
  return 0;
}
