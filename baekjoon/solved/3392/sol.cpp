#include <bits/stdc++.h>

using namespace std;

struct Line {
  int x;
  int ya;
  int yb;
  int type;
  bool operator<(const Line& o) {
    return x < o.x;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = (int) 3e4 + 10;
  int n;
  cin >> n;
  vector<Line> a(2 * n);
  for (int i = 0; i < n; i++) {
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    a[i] = {xa, ya, yb, 1};
    a[i + n] = {xb, ya, yb, -1};
  }
  sort(a.begin(), a.end());
  vector<int> sum(3 * N, 0), add(3 * N, 0);
  function<void(int, int, int, int, int, int)> Modify = [&](int x, int l, int r, int ll, int rr, int v) {
//    cerr << "Modify(" << x << ", " << l << ", " << r << ", " << ll << ", " << rr << ", " << v << ")" << '\n';
    if (ll <= l && r <= rr) {
      add[x] += v;
    } else {
      int y = (l + r) >> 1;
      if (ll <= y) {
        Modify(x + x, l, y, ll, rr, v);
      }
      if (rr > y) {
        Modify(x + x + 1, y + 1, r, ll, rr, v);
      }
    }
    if (add[x] == 0) {
      sum[x] = (l == r) ? 0 : sum[x + x] + sum[x + x + 1];
    } else {
      sum[x] = r - l + 1;
    }
  };
  int ans = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (i > 0) {
      ans += (a[i].x - a[i - 1].x) * sum[1];
    }
    Modify(1, 0, N - 1, a[i].ya, a[i].yb - 1, a[i].type);
  }
  cout << ans << '\n';
  return 0;
}
