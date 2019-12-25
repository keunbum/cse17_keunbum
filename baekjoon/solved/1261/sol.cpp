#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 123;
const int inf = (int) 1e9;

string a[N];
int cost[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  fill_n(cost[0], N * N, inf);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cost[0][0] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
  s.emplace(cost[0][0], 0 * m + 0);
  while (!s.empty()) {
    int c = s.top().second;
    s.pop();
    div_t q = div(c, m);
    int x = q.quot;
    int y = q.rem;
    for (int t = 0; t < 4; t++) {
      int i = x + "2101"[t] - '1';
      int j = y + "1210"[t] - '1';
      if (i < 0 || i >= n || j < 0 || j >= m) continue;
      if (cost[x][y] + a[i][j] - '0' < cost[i][j]) {
        cost[i][j] = cost[x][y] + a[i][j] - '0';
        s.emplace(cost[i][j], i * m + j);
      }
    }
  }
  cout << cost[n - 1][m - 1] << '\n';
  return 0;
}
