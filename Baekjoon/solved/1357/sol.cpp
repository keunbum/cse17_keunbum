#include <bits/stdc++.h>

using namespace std;

int R(int x) {
  int res = 0;
  while (x > 0) {
    res = res * 10 + x % 10;
    x /= 10;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  cin >> x >> y;
  cout << R(R(x) + R(y)) << '\n';
  return 0;
}
