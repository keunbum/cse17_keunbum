#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  int srx = -1, sry = -1;
  int sbx = -1, sby = -1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 'R') {
        srx = i;
        sry = j;
      }
      if (s[i][j] == 'B') {
        sbx = i;
        sby = j;
      }
    }
  }
  vector<tuple<int, int, int, int>> que;
  que.emplace_back(srx, sry, sbx, sby);
  for (int i = 0; i < (int) que.size(); i++) {
    int rx, ry, bx, by;
    tie(rx, ry, bx, by) = que[i];

  }
  return 0;
}
