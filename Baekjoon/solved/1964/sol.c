#include <stdio.h>

const int mod = 45678;

int main() {
  long n;
  scanf("%ld", &n);
  n = 3 * n * n + 5 * n + 2;
  n >>= 1;
  printf("%ld\n", n % mod);
  return 0;
}