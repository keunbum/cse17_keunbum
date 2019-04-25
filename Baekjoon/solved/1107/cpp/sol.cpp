#include <iostream>
#include <algorithm>

using namespace std;

bool b[10];
int N, M, t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  while (M--) {
    cin >> t;
    b[t] = true;
  }
  int ans = abs(100 - N);
  if (!b[0]) ans = min(ans, N + 1);
  for (int i = 1; i < (int) 1e6; i++) {
    int s = 0;
    t = i;
    while (t) {
      if (b[t % 10]) break;
      s++;
      t /= 10;
    }
    if (t) continue;
    ans = min(ans, s + abs(N - i));
  }
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
