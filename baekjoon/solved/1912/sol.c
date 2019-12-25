#include <stdio.h>

int a[123456];

inline int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int ans = a[0];
  for (int i = 1; i < n; i++) {
    a[i] = max(a[i - 1] + a[i], a[i]);
    ans = max(ans, a[i]);
  }
  printf("%d\n", ans);
  return 0;
}