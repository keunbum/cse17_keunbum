#include <iostream>

using namespace std;

int ans[123456];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 1; i <= (int) 1e5; i++) {
    int t = i;
    while (t != 1) {
      ans[i] = max(ans[i], t);
      if (t & 1) t = t * 3 + 1;
      else t >>= 1;
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cout << ans[n] << '\n';
  }
  return 0;
}