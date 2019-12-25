#include <iostream>
#include <complex>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  complex<double> x(a, b), y(c, d), z(e, f);
  auto v = imag(conj((y - x)) * (z - y));
  cout << (v == 0 ? 0 : v > 0 ? 1 : -1) << '\n';
  return 0;
}