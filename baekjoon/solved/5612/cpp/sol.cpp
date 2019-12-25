#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int cur, n, ans = 0;
  cin >> n >> cur;
  for (int i = 0; i < n; i++) {
    int in, out;
    cin >> in >> out;
    cur += in - out;
    ans = max(ans, cur);
    if (cur < 0) {
      ans = 0;
      break;
    }
  }
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
