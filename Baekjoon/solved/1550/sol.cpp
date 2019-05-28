#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int ans = 0;
  int n = (int) s.size();
  for (int i = n - 1, e = 1; i >= 0; i--, e *= 16) {
    s[i] -= s[i] >= 'A' ? 'A' - 10 : '0';
    ans += s[i] * e;
  }
  cout << ans << '\n';
  return 0;
}