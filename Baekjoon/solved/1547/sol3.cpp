#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m;
  cin >> m;
  int a = 1;
  while (m--) {
    int x, y;
    cin >> x >> y;
    if (a == x) a = y; else
    if (a == y) a = x;
  }
  cout << a << '\n';
  return 0;
}