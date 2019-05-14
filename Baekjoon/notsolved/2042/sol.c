#include <stdio.h>

long long v[2345678];

int main() {
  int n, m, k, off;
  scanf("%d %d %d", &n, &m, &k);
  for (off = 1; off <= n; off <<= 1) ;
  for (int i = 1; i <= n; i++) { scanf("%I64d", v + i + off); }
  for (int i = off; i > 1; i--) { v[i] = v[i << 1] + v[i << 1 | 1]; }
  for (int i = 0; i < m + k; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a & 1) {
      long long c;
      scanf("%I64d", &c);
      b += off;
      v[b] = c;
      while (b >>= 1) { v[b] = v[b << 1] + v[b << 1 | 1]; }
    } else {
      int c;
      scanf("%d", &c);
      b += off;
      c += off;
      long long ans = 0LL;
      while (b <= c) {
        if (b & 1) ans += v[b];
        if (~c & 1) ans += v[c];
        b = (b + 1) >> 1;
        c = (c - 1) >> 1;
      }
      printf("%I64d\n", ans);
    }
  }
  return 0;
}