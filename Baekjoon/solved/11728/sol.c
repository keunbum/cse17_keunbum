#include <stdio.h>

int a[1234567], b[1234567];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < m; i++) scanf("%d", b + i);
  a[n] = b[m] = (int) 1e9;
  int p_a = 0, p_b = 0;
  while (p_a < n || p_b < m) {
    if (a[p_a] < b[p_b]) {
      printf("%d ", a[p_a]);
      ++p_a;
    } else {
      printf("%d ", b[p_b]);
      ++p_b;
    }
  }
  return 0;
}