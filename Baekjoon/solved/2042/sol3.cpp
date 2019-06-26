#include <iostream>

using namespace std;

long long v[2345678];

int main() {
  int n, m, k, off;
  cin >> n >> m >> k;
  for (off = 1; off <= n; off <<= 1) ;
  for (int i = 1; i <= n; i++) {
    cin >> v[i + off];
  }
  for (int i = off; i > 1; i--) { 
    v[i] = v[i << 1] + v[(i << 1) | 1];
  }
  m += k;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a & 1) {
      b += off;
      v[b] = c;
      while (b >>= 1) {
        v[b] = v[b << 1] + v[(b << 1) | 1];
      }
    } else {
      b += off;
      c += off;
      long long ans = 0;
      while (b <= c) {
        if (b & 1) {
          ans += v[b];
        }
        if (~c & 1) {
          ans += v[c];
        }
        b = (b + 1) >> 1;
        c = (c - 1) >> 1;
      }
      cout << ans << '\n';
    }
  }
  return 0;
}