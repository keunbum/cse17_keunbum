#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m;
  cin >> m;
  int set = 0;
  while (m--) {
    string cmd;
    cin >> cmd;
    if (cmd == "all") { set = (1 << 21) - 1; continue; }
    if (cmd == "empty") { set = 0; continue; }
    int x;
    cin >> x;
    if (cmd == "add") { set |= (1 << x); } else
    if (cmd == "remove") { set &= ~(1 << x); } else
    if (cmd == "check") { cout << ((set >> x) & 1) << '\n'; } else
    if (cmd == "toggle") { set ^= (1 << x); }
  }
  return 0;
}