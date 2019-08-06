#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  double ans = 1e18;
  for ( ; k <= n; k++) {
    for (int b = 1, e = k; e <= n; b++, e++) {
      double sum = 0.;
      for (int i = b; i <= e; i++) { sum += a[i]; }
      double m = sum / k;
      sum = 0.;
      for (int i = b; i <= e; i++) { sum += (a[i] - m) * (a[i] - m); }
      ans = min(ans, (double) sum / k);
    }
  }
  cout << sqrt(ans) << '\n';
  return 0;
}