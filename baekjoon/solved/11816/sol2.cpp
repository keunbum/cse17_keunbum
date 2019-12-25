#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  if (s[0] == '0') {
    if (s[1] == 'x')
      cout << stoi(s, nullptr, 16) << '\n';
    else
      cout << stoi(s, nullptr, 8) << '\n';
  } else {
    cout << s << '\n';
  }
  return 0;
}