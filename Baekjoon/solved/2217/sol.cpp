#include <iostream>
#include <algorithm>

using namespace std;

int a[123456];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, (long long) (n - i) * a[i]);
  }
  cout << ans << '\n';
  return 0;
}