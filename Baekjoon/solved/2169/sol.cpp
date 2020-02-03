#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  const int inf = (int) 1e9;
  vector<vector<int>> dpa(n, vector<int>(m, -inf));
  vector<vector<int>> dpb(n, vector<int>(m, -inf));
  vector<vector<int>> dpc(n, vector<int>(m, -inf));
  dpa[0][0] = a[0][0];
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      for (int j = 0; j < m; j++) {
        dpa[i][j] = a[i][j] + max({dpa[i - 1][j], dpb[i - 1][j], dpc[i - 1][j]});
      }
    }
    for (int j = 1; j < m; j++) {
      dpb[i][j] = a[i][j] + max(dpa[i][j - 1], dpb[i][j - 1]);
    }
    for (int j = m - 2; j >= 0; j--) {
      dpc[i][j] = a[i][j] + max(dpa[i][j + 1], dpc[i][j + 1]);
    }
  }
  cout << max(dpa[n - 1][m - 1], dpb[n - 1][m - 1]);
  return 0;
}
