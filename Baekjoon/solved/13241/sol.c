#include <stdio.h>

int gcd(int a, int b) {
  while (b) {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int g = gcd(a, b);
  printf("%I64d\n", (long long) a / g * b);
  return 0;
}