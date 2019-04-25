#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, g;
  char c;
  cin >> n >> c >> m;
  g = __gcd(n, m);
  cout << n / g << c << m / g << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}