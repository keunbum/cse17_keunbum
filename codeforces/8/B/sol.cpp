#include <iostream>
#include <cstring>

using namespace std;

const int N = 222;

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

int grid[N][N], dist[N][N];
int qx[N * N];
int qy[N * N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int sx = 100;
  int sy = 100;
  string s;
  cin >> s;
  memset(grid, 1, sizeof(grid));
  int x = sx;
  int y = sy;
  grid[x][y] = 0;
  for (char c : s) {
    if (c == 'L') y--; else
    if (c == 'R') y++; else
    if (c == 'U') x--; else
    if (c == 'D') x++;
    grid[x][y] = 0;
  }
  int ex = x;
  int ey = y;
  int expected = (int) s.size();
  int b = 0, e = 1;
  qx[0] = sx;
  qy[0] = sy;
  memset(dist, -1, sizeof(dist));
  dist[sx][sy] = 0;
  while (b < e) {
    for (int dir = 0; dir < 4; dir++) {
      int nx = qx[b] + DX[dir];
      int ny = qy[b] + DY[dir];
      if (grid[nx][ny] == 0 && dist[nx][ny] == -1) {
        qx[e] = nx;
        qy[e] = ny;
        ++e;
        dist[nx][ny] = dist[qx[b]][qy[b]] + 1;
      }
    }
    ++b;
  }
  cout << (dist[ex][ey] == expected ? "OK" : "BUG") << '\n';
  return 0;
}
