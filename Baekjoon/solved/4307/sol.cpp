#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int) 1e6;

int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int l, n;
    cin >> l >> n;
    int mn = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mn = max(mn, min(a[i], l - a[i]));
    }
    sort(a, a + n);
    int mx = max(l - a[0], a[n - 1]);
    cout << mn << ' ' << mx << '\n';
  }
  return 0;
}