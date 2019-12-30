#include <stdio.h>

#define N 1000010

char st[N], s[N];

int main()
{
  scanf("%s", s);
  int top = 0;
  for (int i = 0; s[i]; i++)
  {
    st[++top] = s[i];
    if (top >= 4 && st[top-3] == 'P' && st[top-2] == 'P' && st[top-1] == 'A' && st[top] == 'P') top -= 3;
  }
  printf("%s\n", top == 1 && st[top] == 'P' ? "PPAP" : "NP");
  return 0;
}
