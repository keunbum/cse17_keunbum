#include <stdio.h>

int n, m;
int chk[9];
int v[9];

void dfs(int x) {
  if (x == m) {
    for (int i = 0; i < m; i++) {
      printf("%s%d", i ? " " : "", v[i]);
    }
    puts("");
    return;
  }
  for (int i = 0; i < n; i++) {
    if (chk[i]) continue;
    chk[i] = 1;
    v[x] = i + 1;
    dfs(x + 1);
    chk[i] = 0;
  }
}

int main() {
  scanf("%d %d", &n, &m);
  dfs(0);
  return 0;
}