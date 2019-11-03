#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int inf = (int) 1e9;
  int n, m;
  cin >> n >> m;
  vector<int> fenw1(n, inf), fenw2(n, inf);
  auto Modify1 = [&](int x, int v) {
    while (x < n) {
      fenw1[x] = min(fenw1[x], v);
      x |= (x + 1);
    }
  };
  auto Modify2 = [&](int x, int v) {
    while (~x) {
      fenw2[x] = min(fenw2[x], v);
      x = (x & (x + 1)) - 1;
    }
  };
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    Modify1(i, a[i]);
    Modify2(i, a[i]);
  }
  auto Get = [&](int x, int y) {
    int v = inf;
    int pa = x;
    int pb = (pa | (pa + 1));
    while (pb <= y) {
      v = min(v, fenw2[pa]);
      pa = pb;
      pb = (pa | (pa + 1));
    }
    v = min(v, a[pa]);
    pa = y;
    pb = (pa & (pa + 1)) - 1;
    while (pb >= x) {
      v = min(v, fenw1[pa]);
      pa = pb;
      pb = (pa & (pa + 1)) - 1;
    }
    return v;
  };
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << Get(x, y) << '\n';
  }
  return 0;
}
