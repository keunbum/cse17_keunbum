#include <iostream>

using namespace std;

const int N = 123;
const int inf = (int) 1e9;

int cost[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  fill_n(cost[0], N * N, inf);
  for (int i = 0; i < n; i++) {
    cost[i][i] = 0;
  }
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    cost[x][y] = min(cost[x][y], z);
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      if (cost[i][k] == inf) continue;
      for (int j = 0; j < n; j++) {
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j) cout << ' ';
      cout << (cost[i][j] == inf ? 0 : cost[i][j]);
    }
    cout << '\n';
  }
  return 0;
}