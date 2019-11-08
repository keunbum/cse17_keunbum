#include <stdio.h>

#define N ((int) 1e5)

int cnt[128];
char s[N + 1];

int main() {
  scanf("%s", s);
  int foo = 0;
  for (int i = 0; s[i]; i++) {
    cnt[s[i]]++;
    foo += (s[i] - '0');
  }
  if (!cnt['0'] || foo % 3) {
    puts("-1");
  } else {
    for (char i = '9'; i >= '0'; i--) {
      int t = cnt[i];
      while (t--) {
        putchar(i);
      }
    }
    puts("");
  }
  return 0;
}
