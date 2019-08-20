#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int b[3211];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d, k, c;
  cin >> n >> d >> k >> c;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int s = 1, e = k, cnt = 0, ans = 0;
  for (int i = 0; i < k; i++) {
    if (b[a[i]]++ == 0) cnt++;
  }
  while (s != 0) {
    if (--b[a[s - 1]] == 0) cnt--;
    if (b[a[e]]++ == 0) cnt++;
    ans = max(ans, cnt + !b[c]);
    if (++s == n) s = 0;
    if (++e == n) e = 0;
  }
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
