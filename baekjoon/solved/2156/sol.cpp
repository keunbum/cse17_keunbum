#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10001;

int a1[N], a2[N], a3[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a1[i];
    a2[i] = a1[i];
    a3[i] = a1[i];
  }
  for (int i = 2; i <= n; i++) {
    a1[i] += max(a2[i - 1], a3[i - 1]);
    a2[i] += max(a3[i - 2], max(a1[i - 2], a2[i - 2]));
    a3[i] += max(a3[i - 3], max(a1[i - 3], a3[i - 3]));
  }
  int ans = max(max(a1[n], a2[n]), a3[n]);
  ans = max(max(ans, a3[n- 1]), max(a1[n - 1], a2[n - 1]));
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
