#include <iostream>

using namespace std;

const int md = 45678;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 1, t = 1;
  while (n--) {
    t += 3;
    ans = (ans + t) % md;
  }
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
