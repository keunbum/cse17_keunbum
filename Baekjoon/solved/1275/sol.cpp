#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6;

int a[N];
long long tree[3 * N];

void Build(int x, int l, int r) {
  if (l == r) {
    tree[x] = a[l];
    return;
  }
  int y = (l + r) >> 1;
  Build(x + x, l, y);
  Build(x + x + 1, y + 1, r);
  tree[x] = tree[x + x] + tree[x + x + 1];
}

long long Get(int x, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) {
    return tree[x];
  }
  int y = (l + r) >> 1;
  long long res = 0LL;
  if (rr <= y) {
    res =  Get(x + x, l, y, ll, rr);
  } else
  if (ll > y) {
    res = Get(x + x + 1, y + 1, r, ll, rr);
  } else {
    res = Get(x + x, l, y, ll, rr) + Get(x + x + 1, y + 1, r, ll, rr);
  }
  return res;
}

void Modify(int x, int l, int r, int p, int v) {
  if (l == r) {
    tree[x] = v;
    return;
  }
  int y = (l + r) >> 1;
  if (p <= y) {
    Modify(x + x, l, y, p, v);
  } else {
    Modify(x + x + 1, y + 1, r, p, v);
  }
  tree[x] = tree[x + x] + tree[x + x + 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, tt;
  cin >> n >> tt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  Build(1, 0, n - 1);
  while (tt--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if (x > y) {
      swap(x, y);
    }
    --x; --y; --a;
    cout << Get(1, 0, n - 1, x, y) << '\n';
    Modify(1, 0, n - 1, a, b);
  }
  return 0;
}