#include <stdio.h>

#define MAX 10000

int p[MAX + 1];

inline int IsPrime(int x) {
  if (x < 2) return 0;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}

int Get(int v) {
  return v == p[v] ? v : (p[v] = Get(p[v]));
}

int main() {
  for (int i = 1; i <= MAX; i++) p[i] = i;
  for (int i = 1; i <= MAX; i++) {
    int x = i;
    int y = 0;
    while (x) {
      y += (x % 10) * (x % 10);
      x /= 10;
    }
    p[Get(i)] = Get(y);
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int qq, m;
    scanf("%d %d", &qq, &m);
    printf("%d %d ", qq, m);
    if (IsPrime(m) && Get(m) == 1) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}