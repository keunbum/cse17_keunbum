#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(11);
  cout << fixed;
  int n, k;
  cin >> n >> k;
  vector<long long> a(n + 1), s(n + 1), ss(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
    ss[i] = ss[i - 1] + a[i] * a[i];
  }
  long double sx, ssx, ans = 9e18;
  for (int size = k; size <= n; size++) {
    for (int b = 1, e = size; e <= n; b++, e++) {
      sx = s[e] - s[b - 1];                         
      ssx = ss[e] - ss[b - 1];
      sx /= size;
      ssx /= size;        
      ans = min(ans, ssx - sx * sx);              
    }                                             
  }
  cout << sqrt(ans) << '\n';
  return 0;
}