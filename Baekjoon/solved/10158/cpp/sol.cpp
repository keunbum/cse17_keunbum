#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int w, h, p, q, t;
  cin >> w >> h >> p >> q >> t;
  p += t;
  q += t;
  p = (p / w) & 1 ? (w - p % w) : p % w;
  q = (q / h) & 1 ? (h - q % h) : q % h;
  cout << p << ' ' << q << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
