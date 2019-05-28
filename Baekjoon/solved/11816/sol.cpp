#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  auto hi = [&](string &s, int base) {
    int i = base / 8;
    int n = (int) s.size();
    int res = 0;
    for ( ; i < n; i++) {
      s[i] -= (s[i] < '0' || s[i] > '9') ? ('a' - 10) : '0';
      res = (res * base) + s[i];
    }
    return res;
  };
  if ("0x" == s.substr(0, 2)) cout << hi(s, 16) << '\n'; else
  if ('0' == s[0]) cout << dec << hi(s, 8) << '\n';
  else cout << s << '\n';
  return 0;
}