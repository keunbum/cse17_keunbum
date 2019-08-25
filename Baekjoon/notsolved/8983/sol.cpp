#include <bits/stdc++.h>

using namespace std;

struct Point {
  int x;
  int y;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n, l;
  cin >> m >> n >> l;
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  vector<Point> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i].x >> b[i].y;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), [&](const Point& p, const Point& q) {
    if (p.x != q.x) {
      return p.x < q.x;
    }
    return p.y < q.y;
  });
  auto Dis = [&](int x, const Point& p) {
    return abs(x - p.x) + p.y;
  };
  int idx = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    while (idx < m - 1 && a[idx + 1] < b[i].x) {
      idx++;
    }
    if ((Dis(a[idx], b[i]) <= l) || (idx < m - 1 && Dis(a[idx + 1], b[i]) <= l)) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
