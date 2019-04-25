#include <iostream>

using namespace std;

const int N = 500;
const int inf = (1 << 31) - 1;

int m[N + 1][N + 1], d[N + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, r, c;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> r >> c;
    d[i] = r;
    d[i + 1] = c;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j + i <= n; j++) {
      m[j][j + i] = inf;
      for (int k = j; k < j + i; k++) {
        m[j][j + i] = min(m[j][j + i], m[j][k] + m[k + 1][j + i] + d[j - 1] * d[k] * d[j + i]);
      }
    }
  }
  cout << m[1][n] << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}