#include <iostream>
#include <cmath>

using namespace std;

const double pi = acos(-1.0);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  int r;
  cin >> r;
  cout << pi * r * r << '\n' << 2 * r * r << '\n';
  return 0;
}