#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int ans = (c - a) * (f - d) - (d - b) * (e - c);
  cout << (ans ? ans > 0 ? 1 : -1 : 0) << '\n';
  return 0;
}