#include <iostream>

using namespace std;

const int N = 15;

int ans = 0, n;
bool chka[N], chkb[2 * N], chkc[2 * N];

void dfs(int x) {
  if (x == n) {
    ans++;
    return;
  }
  for (int y = 0; y < n; y++) {
    if (chka[y] || chkb[x + y] || chkc[x - y + n - 1]) continue;
    chka[y] = chkb[x + y] = chkc[x - y + n - 1] = true; 
    dfs(x + 1);
    chka[y] = chkb[x + y] = chkc[x - y + n - 1] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  dfs(0);
  cout << ans << '\n';
  return 0;
}