#include <iostream>

using namespace std;

char stk[1231231];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, e;
  cin >> s >> e;
  int l = (int) s.size(), n = (int) e.size(), top = 0;
  for (int i = 0; i < l; i++) {
    stk[top++] = s[i];
    if (top < n) continue;
    int j;
    for (j = 0; j < n; j++) {
      if (stk[top - n + j] != e[j]) break;
    }
    if (j == n) top -= n;
  }
  cout << (top ? string(move(stk), top) : "FRULA") << '\n';
  return 0;
}