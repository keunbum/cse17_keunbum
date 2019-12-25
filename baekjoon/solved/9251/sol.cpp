#include <cstdio>
#include <cstring>

using namespace std;

int dp[1234][1234];

inline int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  char s1[1234], s2[1234];
  scanf("%s %s", s1, s2);
  int n1 = strlen(s1);
  int n2 = strlen(s2);
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    }
  }
  printf("%d\n", dp[n1][n2]);
  return 0;
}
