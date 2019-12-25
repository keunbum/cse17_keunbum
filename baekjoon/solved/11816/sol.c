#include <stdio.h>
#include <string.h>

int main() {
  char s[12];
  scanf("%s", s);
  int base = 10;
  int st = 0;
  if (s[0] == '0') {
    if (s[1] == 'x') { base = 16; st = 2; }
    else { base = 8; st = 1; }
  }
  int n = strlen(s);
  int ans = 0;
  for (int i = st; i < n; i++) {
    s[i] -= (s[i] >= '0' && s[i] <= '9') ? '0' : 'a' - 10;
    ans = ans * base + s[i];
  }
  printf("%d\n", ans);
  return 0;
}