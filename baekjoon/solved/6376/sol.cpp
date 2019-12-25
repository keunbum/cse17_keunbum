#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(9);
  cout << fixed;
  int n = 3;
  double e = 2.5;
  cout << "n e" << '\n';
  cout << "- -----------" << '\n';
  cout << "0 1" << '\n';
  cout << "1 2" << '\n';
  cout << "2 2.5" << '\n';
  for (int p = 6; n < 10; n++, p *= n) {
    e += 1.0 / p;
    cout << n << ' ' << e << '\n';
  }
  return 0;
}