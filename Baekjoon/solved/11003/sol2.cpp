#include <bits/stdc++.h>

using namespace std;

const int N = (int) 5e6;
const int inf = 0x3f3f3f3f;
const int _inf = 0x3f;

int a[N];
int fenw_a[N];
int fenw_b[N];

void Modify(int n, int _x, int v) {
  int x = _x;
  while (x < n) {
    fenw_a[x] = min(fenw_a[x], v);
    x |= (x + 1);
  } 
  x = _x;
  while (~x) {
    fenw_b[x] = min(fenw_b[x], v);
    x = (x & (x + 1)) - 1;
  }
}

int Get(int _x, int _y) {
  int res = inf;
  int x = _x;
  int y = (x | (x + 1));
  while (y <= _y) {
    res = min(res, fenw_b[x]);
    x = y;
    y = (x | (x + 1));
  }
  res = min(res, a[x]);
  x = _y;
  y = (x & (x + 1)) - 1;
  while (y >= _x) {
    res = min(res, fenw_a[x]);
    x = y;
    y = (x & (x + 1)) - 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(fenw_a, _inf, sizeof(fenw_a));
  memset(fenw_b, _inf, sizeof(fenw_b));
  int n, l;
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    Modify(n, i, a[i]);
  }
  for (int i = 0; i < n; i++) {
    cout << Get(max(0, i - l + 1), i) << ' ';
  }
  return 0;
}
