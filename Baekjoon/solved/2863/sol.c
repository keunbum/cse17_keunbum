#include <stdio.h>

int i;
int de;
int new_de;

void F(int new_de, int new_i) {
  if (de > new_de) {
    de = new_de;
    i = new_i;
  }
}

int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  de = c * d;
  i = 0;
  F(d * b, 1);
  F(b * a, 2);
  F(a * c, 3);
  printf("%d\n", i);
  return 0;
}