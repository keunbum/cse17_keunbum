#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX 10000

int was[MAX + 1];

int IsPrime(int n) {
  if (n < 2) return 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int IsHappy(int n) {
  memset(was, 0, sizeof(was));
  do {
    was[n] = 1;
    int t = 0;
    while (n) {
      t += (n % 10) * (n % 10);
      n /= 10;
    }
    n = t;
  } while (!was[n]);
  return n == 1;
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int qq, m;
    scanf("%d%d", &qq, &m);
    printf("%d %d %s\n", qq, m, IsPrime(m) && IsHappy(m) ? "YES" : "NO");
  }
  return 0;
}