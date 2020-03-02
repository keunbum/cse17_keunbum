#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  char s[51];
  scanf("%s", s);
  long long ans = 0LL;
  for (int i = n - 1; i >= 0; i--) {
    ans = (ans * 31 + (int) s[i] - 'a' + 1) % 1234567891;
  }
  printf("%lld\n", ans);
  return 0;
}