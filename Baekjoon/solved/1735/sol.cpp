#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y, u, v;
  cin >> x >> y >> u >> v;
  int a = x * v + y * u;
  int b = y * v;
  int g = __gcd(a, b);
  cout << a / g << ' ' << b / g << '\n';
  return 0;
}