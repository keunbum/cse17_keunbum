#include <stdio.h>

#define min(a, b) a < b ? a : b

int c[3];
int m[3];

void Pour(int f, int t) {
  int foo = min(m[f], c[t] - m[t]);
  m[f] -= foo;
  m[t] += foo;
}

int main() {
  for (int i = 0; i < 3; i++) scanf("%d %d", c + i, m + i);
  for (int i = 0; i < 33; i++) {
    Pour(0, 1);
    Pour(1, 2);
    Pour(2, 0);
  }
  Pour(0, 1);
  for (int i = 0; i < 3; i++) printf("%d\n", m[i]);
  return 0;
}