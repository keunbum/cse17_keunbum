#include <stdio.h>

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  if (a == b && b == c) {
    printf("%d\n", (int) 1e4 + a * (int) 1e3);
    return 0;
  }
  if (a == b || a == c) {
    printf("%d\n", (int) 1e3 + a * (int) 1e2);
    return 0;
  }
  if (b == c) {
    printf("%d\n", (int) 1e3 + b * (int) 1e2);
    return 0;
  }
  if (a < b) a = b;
  if (a < c) a = c;
  printf("%d\n", a * (int) 1e2);
//fprintf(stderr, "%f seconds.\n", (float)clock()/CLOCKS_PER_SEC);
  return 0;
}