#include <stdio.h>

#define N 1010
#define inf ((int) 1e9)
#define max(a, b) a > b ? a : b

int a[N];
int ans[N];
int sum[N];

int main() {
  int n, l, w;
  scanf("%d %d %d", &n, &l, &w);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    sum[i] = sum[i - 1] + a[i];
  }
  ans[0] = -inf;
  for (int i = 2; i <= n; i++) {
    int j;
    for (j = i - 1; j > 0; j--) {
      if ((sum[i] - sum[j - 1]) > w) break;
    }
    ans[i] = max(ans[i - 1] + 1, ans[j] + l);
  }
  printf("%d\n", ans[n] + l + 1);
  return 0;
}
