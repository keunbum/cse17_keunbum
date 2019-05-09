#include <stdio.h>

#define N 50

int x[N], y[N], ans[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", x + i, y + i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (x[i] < x[j] && y[i] < y[j]) {
        ans[i]++;
      }
    }
    printf("%d%c", ++ans[i], i == n - 1 ? '\n' : ' ');
  }
//fprintf(stderr, "%f seconds.\n", (float)clock()/CLOCKS_PER_SEC);
  return 0;
}