#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[7], g[7];

void dfs(int v) {
  if (v == m) {
    for (int i = 0; i < m; i++) {
      cout << (i ? " " : "") << g[i];
    }
    cout << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    g[v] = a[i];
    dfs(v + 1);
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
  n = (int) (unique(a, a + n) - a);
  dfs(0);
  return 0;
}