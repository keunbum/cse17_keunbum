// a(n + 1) = 2 * a(n) + 1;
// .
// .
// .
// a(n) = 2^n - 1;

#include <stdio.h>

void dfs(int n, int a, int b) {
  if (n == 1) {
    printf("%d %d\n", a, b);
    return;
  }
  int c = 6 - a - b;
  dfs(n - 1, a, c);
  printf("%d %d\n", a, b);
  dfs(n - 1, c, b);
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", (1 << n) - 1);
  dfs(n, 1, 3);
  return 0;
}