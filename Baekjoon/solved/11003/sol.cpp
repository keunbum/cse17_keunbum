#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 5e6;

int a[MAXN];
int mn[3 * MAXN];

void Build(int x, int l, int r) {
  if (l == r) {
    mn[x] = a[l];
    return;
  }
  int y = (l + r) >> 1;
  Build(x + x, l, y);
  Build(x + x + 1, y + 1, r);
  mn[x] = min(mn[x + x], mn[x + x + 1]);
}

int Get(int x, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) {
    return mn[x];
  }
  int y = (l + r) >> 1;
  if (rr <= y) {
    return Get(x + x, l, y, ll, rr);
  }
  if (ll > y) {
    return Get(x + x + 1, y + 1, r, ll, rr);
  }
  return min(Get(x + x, l, y, ll, rr), Get(x + x + 1, y + 1, r, ll, rr));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l;
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  Build(1, 0, n - 1);
  for (int i = 0; i < n; i++) {
    cout << Get(1, 0, n - 1, max(0, i - l + 1), i) << ' ';
  }
  return 0;
}
