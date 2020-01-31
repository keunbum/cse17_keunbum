#include <stdio.h>

#define MAX1 100010
#define MAX2 200010

int a[MAX2], b[MAX2], p[MAX2];
int last[MAX1], sz[MAX1];

void Dfs(int v, int pr) {
  sz[v] = 1;
  int id = last[v];
  while (id > 0) {
    if (b[id] != pr) {
      Dfs(b[id], v);
      sz[v] += sz[b[id]];
    }
    id = p[id]; 
  }
}

int main() {
  int n, root, tt;
  scanf("%d %d %d\n", &n, &root, &tt);
  int m = n - 1;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", a + i, b + i);
    p[i] = last[a[i]];
    last[a[i]] = i;
    a[i + m] = b[i];
    b[i + m] = a[i];
    p[i + m] = last[b[i]];
    last[b[i]] = i + m;
  }
  Dfs(root, 0);
  while (tt--) {
    int t;
    scanf("%d", &t);
    printf("%d\n", sz[t]);
  }
  return 0;
}