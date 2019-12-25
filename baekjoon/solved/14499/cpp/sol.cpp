#include <iostream>

using namespace std;

const int N = 20;

int n, m, x, y, tt;
int a[N][N];
int vx[4] = {0, 0, -1, 1}, vy[4] = {1, -1, 0, 0};
int dice[6], tmp[6];
int f[4][6] = { // f[d][i] ==> pre index for the i
  {3, 1, 0, 5, 4, 2},
  {2, 1, 5, 0, 4, 3},
  {4, 0, 2, 3, 5, 1},
  {1, 5, 2, 3, 0, 4}
};

inline bool isin(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < m);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> x >> y >> tt;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  int d;
  int nx, ny;
  while (tt--) {
    cin >> d;
    d--;
    nx = x + vx[d];
    ny = y + vy[d];
    if (isin(nx, ny)) {
      x = nx;
      y = ny;
      // figure change
      for (int i = 0; i < 6; i++) {
        //dice[i] = dice[f[d][i]]; This will cause an error.
        tmp[i] = dice[f[d][i]];
      }
      for (int i = 0; i < 6; i++) {
        dice[i] = tmp[i];
      }
      if (a[x][y]) {
        dice[5] = a[x][y];
        a[x][y] = 0;
      } else {
        a[x][y] = dice[5];
      }
      cout << dice[0] << '\n';
    }
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}