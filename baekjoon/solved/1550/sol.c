#include <stdio.h>
#include <string.h>

int main() {
  char s[7];
  scanf("%s", s);
  int ans = 0;
  for (int i = 0; s[i]; i++) {
    ans = ans * 16 + s[i] + (s[i] >= '0' && s[i] <= '9' ? -'0' : -'A' + 10);
  }
  printf("%d\n", ans);
  return 0;
}          