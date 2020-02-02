#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const int N = (int) 3e5;
const int INF = (int) 1e9;

int mn[N];
int mx[N];

void Build(int x, int l, int r, vector<int>& v) {
  if (l == r) {
    mn[x] = mx[x] = v[l];
    return;
  }
  int y = (l + r) >> 1;
  Build(x + x, l, y, v);
  Build(x + x + 1, y + 1, r, v);
  mn[x] = min(mn[x + x], mn[x + x + 1]);
  mx[x] = max(mx[x + x], mx[x + x + 1]);
}

pair<int, int> Get(int x, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) {
    return make_pair(mn[x], mx[x]);
  }
  int y = (l + r) >> 1;
  int res1, res2;
  if (rr <= y) {
    tie(res1, res2) = Get(x + x, l, y, ll, rr);
  } else
  if (ll > y) {
    tie(res1, res2) = Get(x + x + 1, y + 1, r, ll, rr);
  } else {
    int tmn1, tmx1, tmn2, tmx2;
    tie(tmn1, tmx1) = Get(x + x, l, y, ll, rr);
    tie(tmn2, tmx2) = Get(x + x + 1, y + 1, r, ll, rr);
    res1 = min(tmn1, tmn2);
    res2 = max(tmx1, tmx2);
  }
  return make_pair(res1, res2);
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  Build(1, 0, n - 1, a);
  while (m--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    if (x > y) {
      swap(x, y);
    }
    int ans1, ans2;
    tie(ans1, ans2) = Get(1, 0, n - 1, x, y);
    cout << ans1 << ' ' << ans2 << '\n';
  }
  return 0;
}
