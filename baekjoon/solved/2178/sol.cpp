#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int a[123][123];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin.get(c);
      if (c != '0' && c != '1') cin.get(c);
      a[i][j] = c - '0';
    }
  }
  vector<pair<int, int>> q;
  q.emplace_back(1, 1);
  a[1][1] = 2;
  for (int i = 0; i < (int) q.size(); i++) {
    int x, y;
    tie(x, y) = q[i];
    if (x == n && y == m) break;
    for (int j = 0; j < 4; j++) {
      int u = x + "2101"[j] - '1';
      int v = y + "1210"[j] - '1';
      if (a[u][v] == 1) {
        a[u][v] = a[x][y] + 1;
        q.emplace_back(u, v);
      }
    } 
  }
  cout << a[n][m] - 1 << '\n';
  return 0;
}