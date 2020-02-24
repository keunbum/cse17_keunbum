#include <stdio.h>

int main() {
  int a[20];
  for (int i = 0; i < 20; i++) a[i] = i + 1;
  int tt = 10;
  while (tt--)  {
    int x, y;
    scanf("%d %d", &x, &y);
    --x; --y;
    while (x < y) {
      int t = a[y];
      a[y] = a[x];
      a[x] = t;
      ++x;
      --y;
    }
  }
  for (int i = 0; i < 19; i++) printf("%d ", a[i]);
  printf("%d\n", a[19]);
  return 0;
}