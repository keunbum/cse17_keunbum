#include <stdio.h>

int main() {
  int n, f;
  scanf("%d\n%d", &n, &f);
  n = n / 100 * 100;
  int ans = n - n % f;

  return 0;
}