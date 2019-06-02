#include <iostream>

using namespace std;

char stk[123456];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  int ans = 0;
  while (tt--) {
    string s;
    cin >> s;
    int top = 0;
    stk[top++] = s[0];
    int n = (int) s.size();
    for (int i = 1; i < n; i++) {
      if (top > 0 && stk[top - 1] == s[i]) top--;
      else stk[top++] = s[i];
    }
    if (top == 0) ans++;
  }
  cout << ans << '\n';
  return 0;
}