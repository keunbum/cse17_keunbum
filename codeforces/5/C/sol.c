#include <stdio.h>
#include <string.h>

#define N 1000010

int n, e, i, t, max, cnt;
char s[N], good[N];
int stk[N];

int main()
{
  fgets(s, N, stdin);
  memset(good, 1, sizeof(good));
  e = 0;
  for (i = 0; s[i] != '\n'; i++,n++)
  {
    if (s[i] == '(') stk[++e] = i; else
    if (e > 0) e--;
    else good[i] = 0;
  }
  for (i = 1; i <= e; i++) good[stk[i]] = 0;
  t = 0; max = 0; cnt = 1;
  good[n] = 0;
  for (i = 0; i <= n; i++)
  {
    if (good[i]) t++; else
    {
      if (t > max)
      {
        max = t;
        cnt = 0;
      }
      if (t > 0 && t == max) cnt++;
      t = 0;
    }
  }
  printf("%d %d\n", max, cnt);
  return 0;
}
