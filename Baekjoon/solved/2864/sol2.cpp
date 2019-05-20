#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  int mn = a + b, mx = mn, e = 1;
  while (a + b) {
    if (a % 10 == 5) mx += e; else
    if (a % 10 == 6) mn -= e;
    if (b % 10 == 5) mx += e; else
    if (b % 10 == 6) mn -= e;
    e *= 10;
    a /= 10;
    b /= 10;
  }
  cout << mn << ' ' << mx << '\n';
  return 0;
}