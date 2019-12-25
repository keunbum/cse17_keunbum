#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> a[1234];
bool b[1234];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      a[i] = make_pair(y, x);
    }
    sort(a, a + n);
    fill(b, b + m, true);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int j;
      for (j = a[i].second; j <= a[i].first; j++) {
        if (b[j]) break;
      }
      if (j <= a[i].first) {
        ans++;
        b[j] = false;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}