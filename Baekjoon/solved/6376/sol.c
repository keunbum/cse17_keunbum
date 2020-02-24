#include <stdio.h>

int main() {
  puts("n e");
  puts("- -----------");
  puts("0 1");
  puts("1 2");
  puts("2 2.5");
  double acc = 2.5;
  int fac = 2;
  for (int i = 3; i < 10; i++) {
    fac *= i;
    acc += 1.0 / fac;
    printf("%d %.9lf\n", i, acc);
  }
  return 0;
}