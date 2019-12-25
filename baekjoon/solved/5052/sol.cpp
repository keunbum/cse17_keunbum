#include <iostream>
#include <algorithm>

using namespace std;

string a[12345];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    bool ans = true;
    for (int i = 1; i < n; i++) {
      int s = (int) min(a[i - 1].size(), a[i].size());
      bool ok = true;
      for (int j = 0; j < s; j++) {
        if (a[i - 1][j] != a[i][j]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans = false;
        break;
      }
    }
    cout << (ans ? "YES" : "NO") << '\n';
  }
  return 0;
}