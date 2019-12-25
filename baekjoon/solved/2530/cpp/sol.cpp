#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  d += a * 3600 + b * 60 + c;
  a = d / 3600;
  d %= 3600;
  cout <<  a % 24 << ' ' << d / 60 << ' ' << d % 60 << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}