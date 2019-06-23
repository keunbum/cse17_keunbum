#include <iostream>

using namespace std;

const int N = 890;
const int inf = (int) 1e9;

int dist[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, e;
  cin >> n >> e;
  fill_n(dist[0], N * N, inf);
  for (int i = 0; i < n; i++) {
    dist[i][i] = 0;
  }
  while (e--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    dist[x][y] = min(dist[x][y], z);
    dist[y][x] = min(dist[y][x], z);
  }
  int u, v;
  cin >> u >> v;
  u--; v--;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      if (dist[i][k] >= inf) continue;
      for (int j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  long long ans = min((long long) dist[0][u] + dist[u][v] + dist[v][n - 1], (long long) dist[0][v] + dist[v][u] + dist[u][n - 1]);
  cout << (ans < inf ? ans : -1) << '\n';
  return 0;
}