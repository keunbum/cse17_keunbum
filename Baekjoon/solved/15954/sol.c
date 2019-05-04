#include <stdio.h>
#include <math.h>

#define N 500

long long a[N + 1], s[N + 1];

inline double min(double a, double b) {
  return a < b ? a : b;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
    s[i] = s[i - 1] + a[i];
  }
  double ans = 1e18;
  for ( ; k <= n; k++) {
    for (int b = 1, e = k; e <= n; b++, e++) {
      double sum = s[e] - s[b - 1];
      double m = sum / k;
      sum = 0.;
      for (int i = b; i <= e; i++) { sum += (a[i] - m) * (a[i] - m); }
      ans = min(ans, sum / k);
    }
  }
  printf("%.10lf\n", sqrt(ans));
  return 0;
}