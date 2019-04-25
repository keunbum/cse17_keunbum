#include <iostream>

using namespace std;

int m[15][15];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 1; i < 15; i++) {
    m[0][i] = i;
    m[i][1] = 1;
  }
  for (int i = 1; i < 15; i++) {
    for (int j = 2; j < 15; j++) {
      m[i][j] = m[i][j - 1] + m[i - 1][j];
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    cout << m[a][b] << '\n';
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
