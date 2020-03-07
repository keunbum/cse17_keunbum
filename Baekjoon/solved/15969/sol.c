#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int mx = 0;
  int mn = 1000;
  while (n--) {
    int x;
    scanf("%d", &x);
    if (x < mn) mn = x;
    if (x > mx) mx = x;
  }
  printf("%d\n", mx - mn);
  return 0;
}