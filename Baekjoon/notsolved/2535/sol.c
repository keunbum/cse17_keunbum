#include <stdio.h>
#include <stdlib.h>

#define N 123

typedef struct St {
  int con, st, score;
} St;

int comp(const void *arg1, const void *arg2) {
  St a = *(St *) arg1;
  St b = *(St *) arg2;
  return b.score - a.score;
}

int cnt[N];
St a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &a[i].con, &a[i].st, &a[i].score);
  }
  qsort(a, n, sizeof(St), comp);
  int k = 1;
  for (int i = 0; i < n && k < 4; i++) {
    if (cnt[a[i].con]++ >= 2) continue;
    printf("%d %d\n", a[i].con, a[i].st);
    k++;
  }
  return 0;
}