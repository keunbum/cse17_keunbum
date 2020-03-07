#include <stdio.h>

int main() {
  while (1) {
    int a[16];
    int n = 0;
    int was[200] = {0, };
    while (1) {
      scanf("%d", a + n);
      if (a[n] == -1) return 0;
      if (a[n] == 0) break;
      was[a[n]] = 1;
      ++n;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += was[a[i] * 2];
    printf("%d\n", ans);
  }
  return 0;
}