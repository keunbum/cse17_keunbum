#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool chk[123];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    fill_n(chk, 123, false);
    vector<int> a(1);
    int t;
    while (true) {
      cin >> t;
      if (t == -1) return 0; else
      if (t == 0) break;
      chk[t] = true;
      a.push_back(t);
    }
    int ans = 0;
    for (int i = 0; i < (int) a.size(); i++) {
      if ((a[i] & 1) == 0 && chk[a[i] / 2]) {
        ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}