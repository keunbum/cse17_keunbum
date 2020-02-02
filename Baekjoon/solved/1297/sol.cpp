#include <iostream>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int rd, r, c;
  cin >> rd >> r >> c;
  double d = sqrt(r * r + c * c);
  int rr = (int) (rd * r / d);
  int rc = (int) (rd * c / d);
  cout << rr << ' ' << rc << '\n';
  return 0;
}
