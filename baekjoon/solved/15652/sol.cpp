#include <iostream>

using namespace std;

int n, m;
int v[9];

void dfs(int x, int pos) {
  if (x == m) {
    for (int i = 0; i < m; i++) {
      if (i) cout << ' ';
      cout << v[i];
    }
    cout << '\n';
    return;
  }
  for (int i = pos; i < n; i++) {
    v[x] = i + 1;
    dfs(x + 1, i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  dfs(0, 0);
  return 0;
}