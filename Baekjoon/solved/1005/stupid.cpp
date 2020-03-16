#include <iostream>
#include <vector>

using namespace std;

const int N = 1001;

int T[N], dp[N];
vector<vector<int>> g;

int dfs(int n) { // 재귀적으로 탐색 그러나 한번 탐색한 값은 dp이용
  if (dp[n] >= 0) return dp[n]; // 저장 되어 있다
  int mx = 0; // 아무리 작아봤자 0
  for (int u : g[n]) {
    mx = max(mx, dfs(u));
  }
  return dp[n] = T[n] + mx;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    g.clear();
    g.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      dp[i] = -1;
      cin >> T[i];
    }
    while (m--) {
      int x, y;
      cin >> x >> y;
      g[y].push_back(x);
    }
    int w;
    cin >> w;
    cout << dfs(w) << '\n';
  }
  return 0;
}