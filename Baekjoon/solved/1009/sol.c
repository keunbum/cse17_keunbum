#include <stdio.h>

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = 1;
    while (b) {
      if (b & 1) {
        ans = (ans * a) % 10;
      }
      a = (a * a) % 10;
      b /= 2;
    }
    printf("%d\n", ans ? ans : 10);
  }
}