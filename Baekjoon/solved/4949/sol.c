#include <stdio.h>
#include <string.h>

#define MAX 123

int main() {
  char s[MAX];
  char st[MAX];
  while (strcmp(fgets(s, MAX, stdin), ".\n")) {
    int i;
    int top = 0;
    for (i = 0; s[i]; i++) {
      if (s[i] == '(' || s[i] == '[') {
        st[top++] = s[i];
      } else
      if (s[i] == ']') {
        if (!top || st[top - 1] != '[') break;
        --top;
      } else
      if (s[i] == ')') {
        if (!top && st[top - 1] != '(') break;
        --top;
      }
    }
    puts((!s[i] && !top) ? "yes" : "no");
  }
  return 0;
}