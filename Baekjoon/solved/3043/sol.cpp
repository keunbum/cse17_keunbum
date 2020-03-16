#include <bits/stdc++.h>

using namespace std;

struct Point {
  int x;
  int y;
  int id;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<Point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
    --p[i].x; --p[i].y;
    p[i].id = i;
  }
  vector<pair<int, char>> ans;
  {
    sort(p.begin(), p.end(), [&](const Point& pi, const Point& pj) { return pi.x < pj.x; });
    for (int i = 0; i < n; i++) {
      while (p[i].x > i) {
        ans.emplace_back(p[i].id + 1, 'U');
        --p[i].x;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      while (p[i].x < i) {
        ans.emplace_back(p[i].id + 1, 'D');
        ++p[i].x;
      }
    }
  }
  {
    sort(p.begin(), p.end(), [&](const Point& pi, const Point& pj) { return pi.y < pj.y; });
    for (int i = 0; i < n; i++) {
      while (p[i].y > i) {
        ans.emplace_back(p[i].id + 1, 'L');
        --p[i].y;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      while (p[i].y < i) {
        ans.emplace_back(p[i].id + 1, 'R');
        ++p[i].y;
      }
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i].first << ' ' << ans[i].second << '\n';
  }
  return 0;
}
