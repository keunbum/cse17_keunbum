#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int base;
  cin >> s >> base;
  int ans = 0;
  for (char c : s) {
    ans = (ans * base) + c + (c >= '0' && c <= '9' ? -'0' : -'A' + 10);
  }
  cout << ans << '\n';
  return 0;
}