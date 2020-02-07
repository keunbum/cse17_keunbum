#include <iostream>
#include <functional>
#include <iomanip>

using namespace std;

const int N = 1010;

double x[N];
double y[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  double gx, gy, dx, dy;
  cin >> gx >> gy >> dx >> dy;
  int n = 0;
  while (cin >> x[n] >> y[n]) {
    ++n;
  }
  auto Dist2 = [&](double xa, double ya, double xb, double yb) {
    return (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
  };
  int ans_i = -1;
  for (int i = 0; i < n; i++) {
    if (Dist2(gx, gy, x[i], y[i]) * 4.0 <= Dist2(dx, dy, x[i], y[i])) {
      ok = true;
      ans_i = i;
      break;
    }
  }
  if (ans_i >= 0) {
    cout << fixed << setprecision(3) << "The gopher can escape through the hole at (" << x[ans_i] << "," << y[ans_i] << ")." << '\n';
  } else {
    cout << "The gopher cannot escape." << '\n';
  }
  return 0;
}
