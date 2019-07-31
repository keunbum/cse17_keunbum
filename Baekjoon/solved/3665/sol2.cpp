#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1), was(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      was[a[i]] = i;
    }
    int m;
    cin >> m;
    vector<int> now(was);
    while (m--) {
      int x, y;
      cin >> x >> y;
      if (was[x] > was[y]) swap(x, y);
      now[x]++;
      now[y]--;
    }
    sort(a.begin() + 1, a.end(), [&](int i, int j) { return now[i] < now[j]; });
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      if (now[a[i]] != i) {
        ok = false;
        cout << "IMPOSSIBLE" << '\n';
        break;
      }
    }
    if (ok) {
      for (int i = 1; i <= n; i++) {
        if (i > 1) cout << ' ';
        cout << a[i];
      }
      cout << '\n';
    }
  }
  return 0;
}