#include <stdio.h>

int main() {
  while (1) {
    int a[16];
    scanf("%d", a + 0);
    if (a[0] == -1) {
      break;
    }
    int n = 1;
    while (1) {
      scanf("%d", a + n);
      if (a[n] == 0) {
        break;
      }
      ++n;
    }
    int was[100] = {0, };
    for (int i = 0; i < n; i++) {
      was[a[i]] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 0 && was[a[i] / 2]) {
        ++ans;
      }
    }
    printf("%d\n", ans);
  } 
  return 0;
}