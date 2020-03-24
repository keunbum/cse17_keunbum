#include <stdio.h>
#include <math.h>

#define N 20

int x[N];
int y[N];

typedef long long ll;

ll Min(ll a, ll b) { return a < b ? a : b; }

int BitCount(int bs) {
  int res = 0;
  while (bs) {
    ++res;
    bs = bs & (bs - 1);
  }
  return res;
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d%d", x + i, y + i);
    }
    ll ans = (ll) 1e18;
    for (int bs = 0; bs < (1 << n); bs++) {
      if (BitCount(bs) * 2 != n) {
        continue;
      }
      ll vx = 0, vy = 0;
      for (int i = 0; i < n; i++) {
        if (bs & (1 << i)) {
          vx += x[i];
          vy += y[i];
        } else {
          vx -= x[i];
          vy -= y[i];
        }
      }
      ans = Min(ans, vx * vx + vy * vy);
    }
    printf("%.17lf\n", sqrt((double) ans));
  }
  return 0;
}