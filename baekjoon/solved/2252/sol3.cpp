#include <iostream>
#include <queue>
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
  priority_queue<int, vector<int>, greater<int>> s;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) s.push(i);
  }
  while (!s.empty()) {
    int i = s.top();
    s.pop();
    cout << (i + 1) << ' ';
    for (int to : g[i]) {
      if (--deg[to] == 0) {
        s.push(to);
      }
    }
  }
  cout << '\n';
  return 0;
}