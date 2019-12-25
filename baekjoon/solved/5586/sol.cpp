#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int x = 0, y = 0;
  for (int i = 0; i < (int) s.size() - 2; i++) {
    if ("JOI" == s.substr(i, 3)) x++;
    if ("IOI" == s.substr(i, 3)) y++;
  }
  cout << x << '\n' << y;
  return 0;
}