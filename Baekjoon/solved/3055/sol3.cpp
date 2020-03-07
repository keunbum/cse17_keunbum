#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, c;
  cin >> r >> c;
  vector<string> s(r);
  for (int i = 0; i < r; i++) {
    cin >> s[i];
  }
  vector<pair<int, int>> start_q;
  vector<pair<int, int>> flood_q;
  int fx = -1, fy = -1;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (s[i][j] == 'S') {
        s[i][j] = 'X';
        start_q.emplace_back(i, j);
      }
      if (s[i][j] == '*') {
        flood_q.emplace_back(i, j);
        s[i][j] = 'X';
      }
      if (s[i][j] == 'D') {
        fx = i;
        fy = j;
      }
    }
  }
  const int DX[4] = {1, 0, -1, 0};
  const int DY[4] = {0, 1, 0, -1};
  for (int rot = 0; rot < r * c; rot++) {
    {
      s[fx][fy] = 'X';
      vector<pair<int, int>> tq;
      for (int i = 0; i < (int) flood_q.size(); i++) {
        int x, y;
        tie(x, y) = flood_q[i];
        for (int dir = 0; dir < 4; dir++) {
          int nx = x + DX[dir];
          int ny = y + DY[dir];
          if (nx >= 0 && ny >= 0 && nx < r && ny < c && s[nx][ny] != 'X') {
            s[nx][ny] = 'X';
            tq.emplace_back(nx, ny);
          }
        }
      }
      flood_q = tq;
    }
    {
      s[fx][fy] = 'D';
      vector<pair<int, int>> tq;
      for (int i = 0; i < (int) start_q.size(); i++) {
        int x, y;
        tie(x, y) = start_q[i];
        for (int dir = 0; dir < 4; dir++) {
          int nx = x + DX[dir];
          int ny = y + DY[dir];
          if (nx >= 0 && ny >= 0 && nx < r && ny < c && s[nx][ny] != 'X') {
            if (s[nx][ny] == 'D') {
              cout << rot + 1 << '\n';
              return 0;
            }
            s[nx][ny] = 'X';
            tq.emplace_back(nx, ny);
          }
        }
      }
      start_q = tq;
    }
  }
  cout << "KAKTUS" << '\n';
  return 0;
}
