#include <iostream>

using namespace std;

int sum[345][345];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int foo;
      cin >> foo;
      sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + foo;
    }
  }
  int k;
  cin >> k;
  while (k--) {
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    cout << sum[xb][yb] - sum[xb][ya - 1] - sum[xa - 1][yb] + sum[xa - 1][ya - 1] << '\n';
  }
  return 0;
}