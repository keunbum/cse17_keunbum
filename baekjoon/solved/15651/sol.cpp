#include <iostream>

using namespace std;

int n, m;
int v[8];

void dfs(int x) {
  if (x == m) {
    for (int i = 0; i < m; i++) {
      cout << (i ? " " : "") << v[i];
    }
    cout << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    v[x] = i;
    dfs(x + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  dfs(0);
  return 0;
}