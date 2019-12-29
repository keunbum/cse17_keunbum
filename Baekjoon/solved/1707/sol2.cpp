#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    vector<int> c(n);
    iota(p.begin(), p.end(), 0);
    function<int(int)> Get = [&](int v) {
      if (v == p[v]) {
        return p[v];
      }
      c[v] ^= c[p[v]];
      return p[v] = Get(p[v]);
    };
    bool ok = true;
    while (m--) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      int X = Get(x);
      int Y = Get(y);
      int r = c[x] ^ c[y];
      if (X == Y) {
        if (r == 0) {
          ok = false;
        }
        continue;
      }
      p[X] = Y;
      c[X] = r ^ 1;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
