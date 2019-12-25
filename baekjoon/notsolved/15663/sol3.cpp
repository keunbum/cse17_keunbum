#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[8], b[8], g[8];

void dfs(int v) {
  if (v == m) {
    for (int i = 0; i < m; i++) {
      cout << (i ? " " : "") << g[i];
    }
    cout << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!b[i]) continue;
    b[i]--;
    g[v] = a[i];
    dfs(v + 1);
    b[i]++;
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
  int j;
  for (int i = j = 0; i < n; i++) {
    if (!j || a[i] != a[j - 1]) {
      a[j++] = a[i];
    }
    b[j - 1]++;
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
  n = j;
  dfs(0);
  return 0;
}