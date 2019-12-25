#include <iostream>

using namespace std;

inline void add(int &a, int b) {
  a += b;
  if (a >= 45678) a -= 45678;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 1, t = 1;
  while (n--) {
    add(t, 3);
    add(ans, t);
  }
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
