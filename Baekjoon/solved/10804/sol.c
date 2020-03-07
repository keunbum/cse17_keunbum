#include <stdio.h>

int main() {
  int a[21];
  for (int i = 1; i <= 20; i++) {
    a[i] = i;
  }
  int tt = 10;
  while (tt--)  {
    int x, y;
    scanf("%d %d", &x, &y);
    while (x < y) {
      int t = a[y];
      a[y] = a[x];
      a[x] = t;
      ++x;
      --y;
    }
  }
  for (int i = 1; i <= 20; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}