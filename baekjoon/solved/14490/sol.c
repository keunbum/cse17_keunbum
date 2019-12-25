#include <stdio.h>

int gcd(int x, int y) {
  return (x == 0) ? y : gcd(y % x, x);
}

int main() {
  int m, n, g;
  scanf("%d:%d", &n, &m);
  g = gcd(n, m);
  printf("%d:%d\n", n / g, m / g);
  return 0;
}