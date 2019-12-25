#include <stdio.h>

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    char s[51];
    scanf("%s", s);
    int a = 0;
    int ok = 1;
    for (int i = 0; s[i]; i++) {
      if (s[i] == '(') {
        a++;
      } else
      if (a > 0) {
        a--;
      } else {
        ok = 0;
        break;
      }
    }
    printf("%s\n", a == 0 && ok ? "YES" : "NO");
  }
  return 0;
}