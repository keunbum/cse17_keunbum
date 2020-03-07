#include <bits/stdc++.h>

using namespace std;

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

const int MAX = 2510;

int qx[MAX];
int qy[MAX];
int fx[MAX];
int fy[MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, c;
  cin >> r >> c;
  auto IsIn = [&](int x, int y) {
    return x >= 0 && y >= 0 && x < r && y < c;
  };
  vector<string> s(r);
  for (int i = 0; i < r; i++) {
    cin >> s[i];
  }
  int fb = 0, fe = 0;
  int ex = -1, ey = -1;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (s[i][j] == 'S') {
        qx[0] = i;
        qy[0] = j;
        
      }
      if (s[i][j] == '*') {
        fx[fe] = i;
        fy[fe] = j;
        ++fe;
      }
      if (s[i][j] == 'D') {
        ex = i;
        ey = j;
      }
    }
  }
  int qb = 0, qe = 1;
  for (int rot = 0; rot < r * c; rot++) {
    {
      s[ex][ey] = 'X';
      int te = fe;
      while (fb < te) {
        for (int dir = 0; dir < 4; dir++) {
          int nx = fx[fb] + DX[dir];
          int ny = fy[fb] + DY[dir];
          if (IsIn(nx, ny) && s[nx][ny] != 'X' && s[nx][ny] != '*') {
            s[nx][ny] = '*';
            fx[fe] = nx;
            fy[fe] = ny;
            ++fe;
          }
        }
        ++fb;
      }
    }
    {
      s[ex][ey] = 'D';
      int te = qe;
      while (qb < te) {
        for (int dir = 0; dir < 4; dir++) {
          int nx = qx[qb] + DX[dir];
          int ny = qy[qb] + DY[dir];
          if (IsIn(nx, ny) && (s[nx][ny] == '.' || s[nx][ny] == 'D')) {
            if (s[nx][ny] == 'D') {
              cout << rot + 1 << '\n';
              return 0;
            }
            s[nx][ny] = 'X';
            qx[qe] = nx;
            qy[qe] = ny;
            ++qe;
          }
        }
        ++qb;
      }
    }
  }
  cout << "KAKTUS" << '\n';
  return 0;
}
