#include <stdio.h>

int main() {
  int n;
  scanf("%d\n", &n);
  int ans = 0;
  int p = 1234;
  int l = 0;
  while (n--) {
    int c;
    scanf("%d", &c);
    if (c > p) {
      l += c - p;
      if (ans < l) ans = l;
    } else {
      l = 0;
    }
    p = c;
  }
  printf("%d\n", ans);
  return 0;
}
