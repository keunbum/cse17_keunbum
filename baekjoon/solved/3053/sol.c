#include <stdio.h>
#include <math.h>

const double pi = acos(-1);

int main() {
  int r;
  scanf("%d", &r);
  printf("%.10lf\n%.10lf\n", pi * r * r, 2.0 * r * r);
  return 0;
}