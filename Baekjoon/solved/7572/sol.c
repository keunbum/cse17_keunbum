#include <stdio.h>

int main() {
  int n = 2013;
  /*
  for (int i = 0; i < 60; i++) {
    if ((n + i) % 12 + 'A' == 'F' && (n + i) % 10 == 9) {
      printf("%d\n", i);
    }
  }
  */
  scanf("%d", &n);
  n += 56;
  printf("%c%d\n", n % 12 + 'A', n % 10);
  return 0;
}