#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> deg(n, 0);
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
    deg[y]++;
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      ans.push_back(i);
    }
  }
  for (int ptr = 0; ptr < (int) ans.size(); ptr++) {
    int i = ans[ptr];
    for (int to : g[i]) {
      if (--deg[to] == 0) {
        ans.push_back(to);
      }
    }
  }
  for (int x : ans) {
    cout << (x + 1) << ' ';
  }
  cout << '\n';
  return 0;
}