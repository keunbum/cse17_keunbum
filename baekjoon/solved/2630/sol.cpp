#include <iostream>
#include <cassert>

using namespace std;

int ans[2];
int a[128][128];

void dfs(int x, int y, int n) {
  assert(n != 0);
  if (n == 1) { ans[a[x][y]]++; return; }
  int t = a[x][y];
  bool ok = true;
  for (int i = x; i < x + n; i++) {
    for (int j = y; j < y + n; j++) {
      if (t ^ a[i][j]) {
        ok = false;
        i = x + n;
        break;
      }
    }
  }
  if (!ok) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        dfs(x + i * n / 2, y + j * n / 2, n / 2);
      }
    }
  } else {
    ans[t]++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  dfs(0, 0, n);
  cout << ans[0] << ' ' << ans[1] << '\n';
  return 0;
}