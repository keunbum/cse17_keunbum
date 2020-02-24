#include <stdio.h>

int main() {
  puts("10000");
  for (int i = 1; i <= 10000; i++) {
    printf("%d %d\n", i, i);
  }
  return 0;
}