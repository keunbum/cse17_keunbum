#include <iostream>
#include <cmath>

using namespace std;

int a[567];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  double ans = 1e18;
  while (k <= n) {
    for (int b = 1, e = k; e <= n; b++, e++) {
      int sum = 0;
      for (int i = b; i <= e; i++) {
        sum += a[i];
      }
      double m = (double) sum / k;
      double v = 0.0;
      for (int i = b; i <= e; i++) {
        v += (a[i] - m) * (a[i] - m);
      }
      ans = min(ans, v / k);
    }
    k++;
  }
  cout << sqrt(ans) << '\n';
  return 0;
}