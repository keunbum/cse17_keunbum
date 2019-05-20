#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  auto good = [&](string s) {
    int b = 0, e = (int) s.size() - 1;
    while (b <= e) {
      if (s[b++] != s[e--]) return 0;
    }
    return 1;
  };
  cout << good(s) << '\n';
  return 0;
}