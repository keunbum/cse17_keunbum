#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long a, b, c;
    char type, foo;
    cin >> a >> type >> b >> foo >> c;
    if (type == '+') { c -= a + b; }
    if (type == '-') { c -= a - b; }
    if (type == '*') { c -= a * b; }
    if (type == '/') { c -= a / b; }
    cout << (c ? "wrong answer" : "correct") << '\n';
  }
  return 0;
}