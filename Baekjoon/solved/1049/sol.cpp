#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int m1 = (int) 1e9, m2 = (int) 1e9;
  while (m--) {
    int x, y;
    cin >> x >> y;
    m1 = min(m1, x);
    m2 = min(m2, y);
  }
  int ans = min((n + 5) / 6 * m1, n / 6 * m1 + (n % 6) * m2);
  ans = min(ans, n * m2);
  cout << ans << '\n';
  return 0;
}