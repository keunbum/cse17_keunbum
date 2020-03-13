#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    bool ok = true;
    for (int b = i, e = (int) s.size() - 1; b < e; b++, e--) {
      if (s[b] != s[e]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans = (int) s.size() + i;
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}