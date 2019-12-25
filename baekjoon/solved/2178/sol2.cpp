#include <iostream>

using namespace std;

const int N = 123;

string a[N];
int x[N * N], y[N * N];
int b[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  x[0] = 0, y[0] = 0;
  b[0][0] = 1;
  for (int i = 0, e = 1; i < e; i++) {
    if (x[i] == n - 1 && y[i] == m - 1) break;
    for (int j = 0; j < 4; j++) {
      int u = x[i] + "2101"[j] - '1';
      int v = y[i] + "1210"[j] - '1';
      if (u < 0 || u >= n || v < 0 || v >= m || a[u][v] == '0' || b[u][v]) continue;
      b[u][v] = b[x[i]][y[i]] + 1;
      x[e] = u; y[e] = v;
      e++;
    }
  }
  cout << b[n - 1][m - 1] << '\n';
  return 0;
}