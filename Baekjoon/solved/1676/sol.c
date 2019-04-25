#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", n / 5 + n / 25 + n / 125);
//fprintf(stderr, "%f seconds.\n", (float)clock()/CLOCKS_PER_SEC);
  return 0;
}