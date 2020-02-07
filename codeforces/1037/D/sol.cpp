#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> graph(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  for (int i = 0; i < n; i++) {
    sort(graph[i].begin(), graph[i].end());
  }
  vector<int> q(n);
  for (int i = 0; i < n; i++) {
    cin >> q[i];
    --q[i];
  }
  if (q[0] != 0) {
    cout << "No\n";
    return 0;
  }
  int b = 1;
  queue<int> actual_q;
  actual_q.push(0);
  while (b < n && !actual_q.empty()) {
    int v = actual_q.front();
    actual_q.pop();
    while (true) {
      if (b == n || !binary_search(graph[v].begin(), graph[v].end(), q[b])) {
        break;
      }
      actual_q.push(q[b]);
      ++b;
    }
  }
  cout << (b == n ? "Yes" : "No") << '\n';
  return 0;
}
