#include <stdio.h>

int p, x, y;

void F(int a, int b, int c, int d, int q) {
  int _x = a * d + b * c;
  int _y = c * d;
  if (x * _y < _x * y) {
    p = q;
    x = _x;
    y = _y;
  }
}

int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  p = 0;
  x = a * d + b * c;
  y = c * d;
  F(c, a, d, b, 1);
  F(d, c, b, a, 2);
  F(b, d, a, c, 3);
  printf("%d\n", p);
  return 0;
}