#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(9);
  int n = 0;
  double e = 0.;
  cout << "n e" << '\n';
  cout << "- -----------" << '\n';
  for (int p = 1; n < 10; n++, p *= n) {
    e += 1.0 / p;
    if (n > 2) cout << fixed;
    cout << n << ' ' << e << '\n';
  }
  return 0;
}