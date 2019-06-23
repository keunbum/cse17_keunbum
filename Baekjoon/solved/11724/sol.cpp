#include <iostream>
#include <vector>

using namespace std;

bool chk[1234];
vector<vector<int>> a;

void dfs(int v) {
  for (int x : a[v]) {
    if (!chk[x]) {
      chk[x] = true;
      dfs(x);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  a.resize(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!chk[i]) {
      chk[i] = true;
      dfs(i);
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}