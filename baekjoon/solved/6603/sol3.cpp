#include <iostream>
#include <functional>

using namespace std;

int n, a[12], g[6];

void dfs(int v, int pos) {
  if (v == 6) {
    for (int i = 0; i < 6; i++) {
      cout << g[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = pos; i < n; i++) {
    g[v] = a[i];
    dfs(v + 1, i + 1);
  }
}

void solve() {
  dfs(0, 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    cin >> n;
    if (!n) break;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    solve();
    cout << '\n';
  }
  return 0;
}