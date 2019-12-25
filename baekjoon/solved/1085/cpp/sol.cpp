#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y, w, h;
  cin >> x >> y >> w >> h;
  cout << min(min(x, w - x), min(y, h - y)) << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
