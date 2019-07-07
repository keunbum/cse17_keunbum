#include <iostream>

using namespace std;

int a[1234], u[1234], v[1234];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  cin >> a[0];
  fill_n(u, 1234, 1);
  fill_n(v, 1234, 1);
  int ans = 1;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < i; j++) {
      if (a[j] > a[i]) {
        v[i] = max(v[i], max(v[j], u[j]) + 1);
      } else
      if (a[j] < a[i]) {
        u[i] = max(u[i], u[j] + 1);
      }
      ans = max(ans, max(v[i], u[i]));
    }
  }
  cout << ans << '\n';
  return 0;
}