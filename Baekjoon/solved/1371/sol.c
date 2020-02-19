#include <stdio.h>

#define alpha 26
#define N 5050

char s[N];

int main() {
  int cnt[alpha] = {0, };
  while (fgets(s, N, stdin)) {
    for (int i = 0; s[i]; i++) {
      ++cnt[(int) (s[i] - 'a')];
    }
  }
  int mx = 0;
  for (int i = 0; i < alpha; i++) {
    if (cnt[i] > mx) mx = cnt[i];
  }
  for (int i = 0; i < alpha; i++) {
    if (cnt[i] == mx) {
      putchar(i + 'a');
    }
  }
  return 0;
}