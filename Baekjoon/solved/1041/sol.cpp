#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a[6];
  int sum = 0, maxx = 0;
  for (int i = 0; i < 6; i++) {
    cin >> a[i];
    sum += a[i];
    maxx = max(maxx, a[i]);
  }
  int m1 = min(a[0], a[5]);
  int m2 = min(a[1], a[4]);
  int m3 = min(a[2], a[3]);
  int mn = min(m1, min(m2, m3));
  int mx = max(m1, max(m2, m3));
  if (n == 1) { cout << sum - maxx << '\n'; return 0; }
  long long ans = mn * (n - 2) * (5LL * n - 6);
  ans += (m1 + m2 + m3 - mx) * (8LL * n - 12);
  ans += (m1 + m2 + m3) * 4LL;
  cout << ans << '\n';
  return 0;
}