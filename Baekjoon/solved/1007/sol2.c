#include <stdio.h>
#include <math.h>

typedef long long ll;

#define N 20

int n;
int x[N];
int y[N];
ll ans;

void Dfs(int depth, int balance, ll vx, ll vy) {
  if (depth == n) {
    if (balance == 0) {
      ll new_ans = vx * vx + vy * vy;
      if (new_ans < ans) ans = new_ans;
    }
    return;
  }
  Dfs(depth + 1, balance, vx + x[depth], vy + y[depth]);
  if (balance > 0) Dfs(depth + 1, balance - 1, vx - x[depth], vy - y[depth]);
}

int main() {
  int tt, i;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d%d", x + i, y + i);
    }
    ans = (ll) 1e18;
    Dfs(0, n / 2, 0LL, 0LL);
    printf("%.17lf\n", sqrt((double) ans));
  }
  return 0;
}