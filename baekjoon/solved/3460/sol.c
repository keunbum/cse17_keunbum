#include <stdio.h>

const int BITS = 20;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < BITS; i++) {
      if ((n >> i) & 1) printf("%d ", i);
    }
    puts("");
  }
  return 0;
}