#include <iostream>

using namespace std;

int n, m;
int a[8];

void dfs(int x, int y) {
  if (x == m) {
    for (int i = 0; i < m; i++) {
      cout << (i ? " " : "") << a[i];
    }
    cout << '\n';
    return;
  }
  for (int i = y; i < n; i++) {
    a[x] = i + 1;
    dfs(x + 1, i + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  dfs(0, 0);
  return 0;
}