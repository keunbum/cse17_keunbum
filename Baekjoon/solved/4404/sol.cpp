#include <iostream>
#include <cmath>
#include <functional>
#include <iomanip>
#include <string>

using namespace std;

const int N = 1010;
const int E = (int) 1e3;

long long x[N];
long long y[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto Read = [&](long long& x, long long& y) {
    char ch;
    long long a, b;
    if (!(cin >> a >> ch >> b)) {
      return false;
    }
    if (a < 0) b = -b;
    x = a * E + b;
    cin >> a >> ch >> b;
    if (a < 0) b = -b;
    y = a * E + b;
//    cerr << "x = " << x << " y = " << y << '\n';
    return true;
  };
  auto P2 = [&](long long x) { return x * x; };
  auto Dist2 = [&](long long xa, long long ya, long long xb, long long yb) {
    return P2(xb - xa) + P2(yb - ya);
  };
  long long gx, gy, dx, dy;
  Read(gx, gy);
  Read(dx, dy);
  int n = 0;
  while (Read(x[n], y[n])) {
    ++n;
  }
  bool ok = false;
  long long ans_x = -1;
  long long ans_y = -1;
  for (int i = 0; i < n; i++) {
    if (Dist2(gx, gy, x[i], y[i]) * 4 <= Dist2(dx, dy, x[i], y[i])) {
      ok = true;
      ans_x = x[i];
      ans_y = y[i];
      break;
    }
  }
  auto T = [&](long long m) {
    double res;
    long long p = m / E;
    long long q = m % E;
    res = p + (double) q / E;
    return res;
  };
  if (ok) {
    cout << fixed << setprecision(3) << "The gopher can escape through the hole at (" << T(ans_x) << "," << T(ans_y) << ")." << '\n';
  } else {
    cout << "The gopher cannot escape." << '\n';
  }
  return 0;
}
