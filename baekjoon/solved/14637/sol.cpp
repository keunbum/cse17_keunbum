#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  int n, t;
  cin >> n >> t;
  double low = -1e9;
  vector<int> d(n), s(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i] >> s[i];
    low = max(low, -1.0 * s[i]);
  }
  double high = 1e9;
  for (int tt = 0; tt < 100; tt++) {
    double mid = 0.5 * (low + high);
    double sum = 0.0;                 
    for (int i = 0; i < n; i++) {
      sum += (double) d[i] / (s[i] + mid);
    }
    if (sum < t) high = mid;
    else low = mid;
  }
  cout << 0.5 * (low + high) << '\n';
  return 0;
}