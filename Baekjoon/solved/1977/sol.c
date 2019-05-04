#include <stdio.h>
#include <math.h>

int Ceil(double a) {
  int b = (int) a;
  if ((double) b == a) {
    return b;
  }
  return b + 1;
}

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  int sum = 0, low = Ceil(sqrt(m)), high = (int) sqrt(n);
  for (int i = low; i <= high; i++) {
    sum += i * i;
  }
  if (sum) { printf("%d\n%d\n", sum, low * low); }
  else { puts("-1"); }
  return 0;
}