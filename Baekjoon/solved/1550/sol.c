#include <stdio.h>
#include <string.h>

int main() {
  char s[7];
  scanf("%s", s);
  int n = strlen(s);
  int ans = 0;
  for (int i = n - 1, e = 1; i >= 0; i--, e *= 16) {
    s[i] -= s[i] >= 'A' ? 'A' - 10 : '0';
    ans += s[i] * e;
  } 
  printf("%d\n", ans);
  return 0;
}          