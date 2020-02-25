#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, tt;
  cin >> n >> tt;
  vector<int> a(n);
  vector<long long> fenw(n, 0LL);
  auto Modify = [&](int x, long long v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  };
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    Modify(i, a[i]);
  }
  auto Get = [&](int x) {
    long long res = 0LL;
    while (x >= 0) {
      res += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return res;
  };
  while (tt--) {
    int x, y, p, v;
    cin >> x >> y >> p >> v;
    if (x > y) {
      swap(x, y);
    }
    --x; --y; --p;
    cout << Get(y) - Get(x - 1) << '\n';
    Modify(p, (long long) v - a[p]);
    a[p] = v;
  }
  return 0;
}
