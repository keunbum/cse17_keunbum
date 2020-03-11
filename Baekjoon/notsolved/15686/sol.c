#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define inf 0x3f3f3f3f
#define _inf 0x3f

#define min(a, b) a < b ? a : b

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int h_n = 0;
  int c_n = 0;
  int hx[50], hy[50];
  int cx[13], cy[13];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      scanf("%d", &x);
      if (x == 1) {
        hx[h_n] = i;
        hy[h_n] = j;
        ++h_n;
      }
      if (x == 2) {
        cx[c_n] = i;
        cy[c_n] = j;
        ++c_n;
      }
    }
  }
  int ans = inf;
  for (int bs = 1; bs < (1 << c_n); bs++) {
    int cnt = 0;
    int chk[13] = {0, };
    for (int i = 0; i < c_n; i++) {
      if (bs & (1 << i)) {
        ++cnt;
        chk[i] = 1;
      }
    }
    if (cnt != m) {
      continue;
    }
    int ch_dist[100];
    memset(ch_dist, _inf, sizeof(ch_dist));
    for (int h_id = 0; h_id < h_n; h_id++) {
      for (int c_id = 0; c_id < c_n; c_id++) {
        if (chk[c_id]) {
          ch_dist[h_id] = min(ch_dist[h_id], abs(hx[h_id] - cx[c_id]) + abs(hy[h_id] - cy[c_id])); 
        }
      }
    }
    int foo = 0;
    for (int i = 0; i < h_n; i++) {
//      printf("%d ", ch_dist[i]);
      foo += ch_dist[i];
    }
//    puts("");
    ans = min(ans, foo);
  }
  printf("%d\n", ans);
  return 0;
}