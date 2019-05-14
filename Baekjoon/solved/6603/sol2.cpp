#include <iostream>

using namespace std;

int a[12];
bool g[12];

void dfs(int v, int n) {
  if (v == n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (g[i]) cnt++;
    }
    if (cnt == 6) {
      for (int i = 0; i < n; i++) {
        if (g[i]) cout << a[i] << ' ';
      }
      cout << '\n';
    }
    return;
  }
  g[v] = true;
  dfs(v + 1, n);
  g[v] = false;
  dfs(v + 1, n);
}

void solve(int n) {
  dfs(0, n);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    int n;
    cin >> n;
    if (!n) break;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    solve(n);
    cout << '\n';
  }
  return 0;
}