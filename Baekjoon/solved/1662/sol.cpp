#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 60;
  int stk[N];
  char stk_c[N];
  string s;
  cin >> s;
  int top = 0;
  for (char c : s) {
    if (c != ')') {
      stk[top] = 1;
      stk_c[top] = c;
      top++;
    } else {
      int v = 0;
      while (stk_c[top - 1] != '(') {
        v += stk[--top];
      }
      top--;
      stk[top - 1] = (stk_c[top - 1] - '0') * v;
    }
  }
  int ans = 0;
  while (top > 0) {
    ans += stk[--top];
  }
  cout << ans << '\n';
  return 0;
}
