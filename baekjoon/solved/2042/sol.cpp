#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<int> a;
vector<long long> tree;

void build(int x, int l, int r) {
  if (l == r) {
    tree[x] = a[l];
    return;
  }
  int y = (l + r) >> 1;
  int z = x + ((y - l + 1) << 1);
  build(x + 1, l, y);
  build(z, y + 1, r);
  tree[x] = tree[x + 1] + tree[z];
}

long long get(int x, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) {
    return tree[x];
  }
  int y = (l + r) >> 1;
  int z = x + ((y - l + 1) << 1);
  long long res = 0;
  if (rr <= y) {
    res = get(x + 1, l, y, ll, rr);
  } else {
    if (ll > y) {
      res = get(z, y + 1, r, ll, rr);
    } else {
      res = get(x + 1, l, y, ll, rr) + get(z, y + 1, r, ll, rr);
    }
  }
  return res;
}

void modify(int x, int l, int r, int pos, int v) {
  if (l == r) {
    tree[x] = v;
    return;
  }
  int y = (l + r) >> 1;
  int z = x + ((y - l + 1) << 1);
  if (pos <= y) {
    modify(x + 1, l, y, pos, v);
  } else {
    modify(z, y + 1, r, pos, v);
  }
  tree[x] = tree[x + 1] + tree[z];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  tree.resize(2 * n - 1);
  build(0, 0, n - 1);
  m += k;
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    if (x & 1) {
      y--;
      modify(0, 0, n - 1, y, z);
    } else {
      y--; z--;
      cout << get(0, 0, n - 1, y, z) << '\n';
    }
  }
  return 0;
}