#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    string foo;
    cin >> foo;
    if (foo[0] == '0') break;
    int s = 0;
    for (char c : foo) s += c - '0';
    while (s > 9) {
      int t = 0;
      while (s) {
        t += s % 10;
        s /= 10;
      }
      s = t;
    }
    cout << s << '\n';
  }
  return 0;
}