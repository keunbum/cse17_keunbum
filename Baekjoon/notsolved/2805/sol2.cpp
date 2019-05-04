#include <stdio.h>
#include <algorithm>
long long d[1000050];
long long sum[1000050];
int N;
int bin_search(long long a) {
  int st = 1, en = N, mi, ans = N;
  while(st <= en) {
    mi = (st+en)/2;
    if(d[mi] > a) {
      ans = mi;
      en = mi-1;
    }
    else st = mi+1;
  }
  return ans;
}
int main() {
  int M, i;
  scanf("%d %d", &N, &M);
  for(i = 1; i <= N; i++) scanf("%lld", &d[i]);
  std::sort(d+1, d+N+1);
  sum[N] = d[N];
  for(i = N-1; i >= 1; i--) sum[i] = sum[i+1]+d[i];
  long long st = 0, en = d[N], mi, ans = 0, t;
  while(st <= en) {
    mi = (st+en)/2;
    t = bin_search(mi);
    if(sum[t] - (N-t+1)*mi >= M) {
      ans = mi;
      st = mi+1;
    }
    else en = mi-1;
  }
  printf("%d", ans);
  return 0;
}