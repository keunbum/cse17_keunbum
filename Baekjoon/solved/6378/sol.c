#include <stdio.h>
#include <string.h>

int main() {
  char foo[1234];
  while (1) {
    scanf("%s", foo);
    if (foo[0] == '0') break;
    int sz = (int) strlen(foo);
    int s = 0;
    for (int i = 0; i < sz; i++) {
      s += foo[i] - '0';
    }
    while (s > 9) {
      int t = 0;
      while (s) {
        t += s % 10;
        s /= 10;
      }
      s = t;
    }
    printf("%d\n", s);
  }
  return 0;
}