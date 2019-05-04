#include <stdio.h>
#include <stdlib.h>

#define N ((int) 1e6)

int a[N + 1], sum[N + 1];

int cmp(const void *a, const void *b) {
  return *(int *)b - *(int *)a;
} 

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    sum[i] = sum[i - 1] + a[i];
  }
  qsort(a + 1, n, sizeof(int), cmp);
  for (int i = 1; i <= n; i++) {
    fprintf(stderr, "%d\n", a[i]);
  }
  int b = 0, e = (int) 2e9, ans = 0;
  for (int i = 0; i < 50; i++) {
    ans = (b + e) / 2;
    int f = b_s(a + b
  }
//fprintf(stderr, "%f seconds.\n", (float)clock()/CLOCKS_PER_SEC);
  return 0;
}