#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX 10000

int prime[MAX + 1];

int main() {
  memset(prime, 1, sizeof(prime));
  prime[1] = 0;
  for (int i = 2; i <= MAX; i++) {
    if (!prime[i]) continue;
    for (int j = i + i; j <= MAX; j += i) {
      prime[j] = 0;
    }
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int qq, m;
    scanf("%d %d", &qq, &m);
    printf("%d %d ", qq, m);
    if (!prime[m]) {
      puts("NO");
      continue;
    }
    for (int i = 0; i < 6; i++) {
      int t = 0;
//      printf("m = %d\n", m);
      while (m) {
        t += (m % 10) * (m % 10);
        m /= 10;
      }
      m = t;
    }
    puts(m == 1 ? "YES" : "NO");
  }
  return 0;
}