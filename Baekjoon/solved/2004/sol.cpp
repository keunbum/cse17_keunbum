#include <iostream>

using namespace std;

int f(int x, int y) {
  int r = 0;
  while (x > 0) {
    x /= y;
    r += x;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int foo = f(n, 5) - f(m, 5) - f(n - m, 5);
  int bar = f(n, 2) - f(m, 2) - f(n - m, 2);
  cout << min(foo, bar) << '\n';
  return 0;
}