#include <iostream>

using namespace std;

int f(int n, int m) {
  if (m == 1) {
    return n - 1;
  }
  int r = f(n, m / 2);
  r = 2 * r + 1 + (m & 1) * n;
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  cout << f(n, m) << '\n';
  return 0;
}