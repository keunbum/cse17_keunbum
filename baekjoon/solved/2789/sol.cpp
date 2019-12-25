#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  for (char c : s) {
    bool ok = true;
    for (char d : "CAMBRIDGE") {
      if (c == d) {
        ok = false;
        break;
      }
    }
    if (ok) cout << c;
  }
  return 0;
}