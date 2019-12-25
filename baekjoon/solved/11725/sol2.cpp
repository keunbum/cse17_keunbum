#include <iostream>
#include <list>

using namespace std;

const int N = 123456;

int ans[N];
list<int> g[N];

void dfs(int v) {
  for (int u : g[v]) {
    if (ans[u] == 0) {
      ans[u] = v;
      dfs(u);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  ans[1] = 1;
  dfs(1);
  for (int i = 2; i <= n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}