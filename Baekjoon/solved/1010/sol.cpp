#include <iostream>

using namespace std;

int c[34][34];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 1; i < 34; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    cout << c[m][n] << '\n';
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}