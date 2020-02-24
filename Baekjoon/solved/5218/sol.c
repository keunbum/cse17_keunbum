#include <stdio.h>

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int i;
    char a[22];
    char b[22];
    printf("Distances:");
    scanf("%s %s", a, b);
    for (i = 0; a[i]; i++) {
      int t = b[i] - a[i];
      if (t < 0) t += 26;
      printf(" %d", t);
    }
    puts("");
  }
  return 0;
}