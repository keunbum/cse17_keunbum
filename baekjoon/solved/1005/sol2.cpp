#include <iostream>
#include <vector>

using namespace std;

const int N = 1001;

int T[N], dp[N];
vector<vector<int>> g;

int dfs(int n) { // ��������� Ž�� �׷��� �ѹ� Ž���� ���� dp�̿�
  if (dp[n] >= 0) return dp[n]; // ���� �Ǿ� �ִ�
  int mx = 0; // �ƹ��� �۾ƺ��� 0
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