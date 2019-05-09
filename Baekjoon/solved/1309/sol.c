#include <stdio.h>

#define N 123123
#define md 9901

int a[N][2];

int main() {
  int n;
  scanf("%d", &n);
  a[0][0] = a[0][1] = 1;
  for (int i = 1; i <= n; i++) {
    a[i][0] = (a[i - 1][0] + a[i - 1][1] * 2) % md;
    a[i][1] = (a[i - 1][0] + a[i - 1][1]) % md;
  }
  printf("%d\n", a[n][0]);
  return 0;
}