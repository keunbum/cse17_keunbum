#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long inf = (long long) 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    g[x].emplace_back(y, z);
  }
  int st, en;
  cin >> st >> en;
  st--; en--;
  vector<long long> ans(n, inf);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> s;
  ans[st] = 0;
  s.emplace(ans[st], st);
  while (!s.empty()) {
    long long expected = s.top().first;
    int i = s.top().second;
    s.pop();
    if (expected != ans[i]) continue;
    for (auto &e : g[i]) {
      if (ans[i] + e.second < ans[e.first]) {
        ans[e.first] = ans[i] + e.second;
        s.emplace(ans[e.first], e.first);
      }
    }
  }
  cout << ans[en] << '\n';	
  return 0;
}