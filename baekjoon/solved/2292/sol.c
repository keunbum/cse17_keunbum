#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int i, sum = 1;
  for (i = 0; n > sum; i++) {
    sum += 6 * (i + 1);
  }
  printf("%d\n", i + 1);
  return 0;
}