#include <stdio.h>

int a[123456];

int main() {
  int n;
  scanf("%d", &n);
  a[1] = 3;
  a[2] = 7;
  for (int i = 3; i <= n; i++) {
    a[i] = (2 * a[i - 1] + a[i- 2]) % 9901;
  }
  printf("%d\n", a[n]);
  return 0;
}