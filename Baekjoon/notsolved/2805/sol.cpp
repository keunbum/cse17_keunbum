#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int &foo : a) {
    cin >> foo;
  }
  sort(a.rbegin(), a.rend());
  int b = 0, e = (int) 2e9, ans;
  for (int i = 0; i < 50; i++) {
    ans = (b + e) / 2;
    long w = 0;
    for (int &foo : a) {
      if (foo <= ans) break;
      w += foo - ans;
    }
    if (w == m) break;
    if (w > m) b = ans + 1;
    else e = ans - 1;
  }
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}