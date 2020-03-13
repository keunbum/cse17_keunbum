#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto Read = [&](int& x, int& y) {
    string s;
    cin >> s;
    x = (int) (s[0] - 'A');
    y = (int) (s[1] - '1');
  };
  int kx, ky, sx, sy;
  Read(kx, ky);
  Read(sx, sy);
  auto Write = [&](int x, int y) {
    cout << (char) (x + 'A') << (char) (y + '1') << '\n';
  };
  int n;
  cin >> n;
  while (n--) {
//    cerr << "(" << kx << ", " << ky << ")" << '\n';
//    cerr << "(" << sx << ", " << sy << ")" << '\n';
    int dx = 0, dy = 0;
    string s;
    cin >> s;
    for (char c : s) {
      if (c == 'R') dx = 1;
      if (c == 'L') dx = -1;
      if (c == 'B') dy = -1;
      if (c == 'T') dy = 1;
    }
    int nkx = kx + dx;
    int nky = ky + dy;
    if (nkx < 0 || nky < 0 || nkx > 7 || nky > 7) {
      continue;
    }
    if (nkx == sx && nky == sy) {
      int nsx = sx + dx;
      int nsy = sy + dy;
      if (nsx < 0 || nsy < 0 || nsx > 7 || nsy > 7) {
        continue;
      }
      sx = nsx, sy = nsy;
    } 
    kx = nkx, ky = nky;
  }
//  cerr << "(" << kx << ", " << ky << ")" << '\n';
//  cerr << "(" << sx << ", " << sy << ")" << '\n';
  Write(kx, ky);
  Write(sx, sy);
  return 0;
}
