#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[8], g[8];

void dfs(int v, int pos) {
  if (v == m) {
    for (int i = 0; i < m; i++) {
      if (i) cout << ' ';
      cout << g[i];
    }
    cout << '\n';
    return;
  }
  for (int i = pos; i < n; i++) {
    g[v] = a[i];
    dfs(v + 1, i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  dfs(0, 0);
  return 0;
}