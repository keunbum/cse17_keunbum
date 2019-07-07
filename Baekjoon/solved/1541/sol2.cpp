#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int ans = 0;
  int v = 0;
  int sign = 1;
  for (char c : s) {
    if (c >= '0' && c <= '9') {
      v = v * 10 + c - '0';
      continue;
    } 
    ans += sign * v;
    v = 0;
    if (c == '-') sign = -1;
  }
  ans += sign * v;
  cout << ans << '\n';
  return 0;
}
