#include <iostream>
#include <vector>

using namespace std;

const int md = (int) 1e3;

inline int mul(int a, int b) {
  return a * b % md;
}

inline vector<vector<int>> Mul(vector<vector<int>> &x, vector<vector<int>> &y, int n) {
  vector<vector<int>> r(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        r[i][j] += mul(x[i][k], y[k][j]);
      }
      r[i][j] %= md;
    }
  }
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long b;
  cin >> n >> b;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> ans(n, vector<int>(n));
  for (int i = 0; i < n; i++) { ans[i][i] = 1; }
  while (b) {
    if (b & 1) {
      ans = Mul(ans, a, n);
    }
    a = Mul(a, a, n);
    b >>= 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      cout << ans[i][j] << ' ';
    }
    cout << ans[i][n - 1] << '\n';
  }
  return 0;
}