#include <stdio.h>

int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  int mn = x + y;
  int mx = x + y;
  int e = 1;
  while (x + y) {
    int X = x % 10;
    int Y = y % 10;
    if (X == 5) mx += e; else
    if (X == 6) mn -= e;
    if (Y == 5) mx += e; else
    if (Y == 6) mn -= e;
    x /= 10;
    y /= 10;
    e *= 10;
  }
  printf("%d %d\n", mn, mx);
  return 0;
}