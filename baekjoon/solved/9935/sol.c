#include <stdio.h>
#include <string.h>

#define N 1231231

int top, j;
char s[N], stk[N], e[50];

int main() {
  scanf("%s %s", s, e);
  int n = strlen(e);
  for (int i = 0; s[i]; i++) {
    stk[top++] = s[i];
    if (top < n) continue;
    for (j = 0; j < n; j++) {
      if (stk[j + top - n] != e[j]) break;
    }
    if (j == n) top -= n;
  }
  stk[top] = 0;
  puts(top ? stk : "FRULA");
  return 0;
}