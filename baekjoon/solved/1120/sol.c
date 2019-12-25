#include <stdio.h>
#include <string.h>

int main() {
  char A[51], B[51];
  scanf("%s %s", A, B);
  int n = strlen(A);
  int m = strlen(B);
  int ans = n;
  for (int i = 0; i <= m - n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (A[j] - B[i + j]) cnt++;
    }
    if (cnt < ans) ans = cnt;
  } 
  printf("%d\n", ans); 
  return 0;
}