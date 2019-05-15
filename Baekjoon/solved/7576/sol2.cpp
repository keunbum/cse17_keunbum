#include <iostream>
#include <vector>

using namespace std;

const int N = 1234;

int to, ripe;
int a[N][N];
vector<pair<int, int>> que;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) a[i][j] = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int t;
      cin >> t;
      a[i][j] = t;
      if (t != -1) to++;
      if (t == 1) {
        ripe++;
        que.emplace_back(i, j);
      }
    }
  }
  if (to == ripe) { cout << 0 << '\n'; return 0; }
  int i;
  for (i = 0; i < (int) que.size(); i++) {
    int cx = que[i].first;
    int cy = que[i].second;
    for (int j = 0; j < 4; j++) {
      int x = cx + "2101"[j] - '1';
      int y = cy + "1210"[j] - '1';
      if (a[x][y] != 0) continue;
      ripe++;
      a[x][y] = a[cx][cy] + 1;
      que.emplace_back(x, y);
    }
  }
  if (to == ripe) { cout << a[que[i - 1].first][que[i - 1].second] - 1 << '\n'; }
  else cout << -1 << '\n';
  return 0;
}