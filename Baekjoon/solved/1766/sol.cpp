#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 32001;

int deg[N];
vector<int> g[N];
priority_queue<int, vector<int>, greater<int>> s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    deg[y]++;
  }
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) {
      s.push(i);
    }
  }
  while (!s.empty()) {
    int i = s.top();
    s.pop();
    cout << i << ' ';
    for (int to : g[i]) {
      if (--deg[to] == 0) {
        s.push(to);
      }
    }
  }
  return 0;
}