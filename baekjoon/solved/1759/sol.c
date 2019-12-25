#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int l, n;
char a[16];
int b[16];

int cmp(const void *a, const void *b) {
  return (*(char *)a - *(char *)b);                        
}

inline int ismo(char c) {
  char *s = "aeiou";
  for (int i = 0; i < 5; i++) {
    if (c == s[i]) return 1;
  }
  return 0;
}      

void dfs(int v, int pos) {
  if (v == l) {
    int cnt = 0, mo = 0, ja = 0;
    char s[16];
    for (int i = 0; i < n; i++) {
      if (b[i]) {
        s[cnt++] = a[i];
        if (ismo(a[i])) mo++;
        else ja++;
      }
    }
    s[cnt] = 0;
    if (mo >= 1 && ja >= 2) {
      puts(s);
    }
    return;
  }
  for (int i = pos; i < n; i++) {
    b[i] = 1;
    dfs(v + 1, i + 1);
    b[i] = 0;
  }
}

void solve() {
  dfs(0, 0);
}

int main() {
  scanf("%d %d\n", &l, &n);
  for (int i = 0; i < n; i++) {
    scanf("%c ", a + i);
  }
  memset(b, 0, sizeof(b));
  qsort(a, n, sizeof(char), cmp);
  solve();
  return 0;
}