#include <iostream>

using namespace std;

inline void f(int w, int h, int k) {
  int x = h, y = 0;
  int dir = 2, sh = h + 1, sw = w, cnt = 0;
  while (1) {
    if (k < sh + cnt) {
      cout << y + 1 << ' ' << h - (x += ("2101"[dir] - '1') * (k - cnt)) << '\n';
      return;
    }
    x += ("2101"[dir] - '1') * (--sh);
    cnt += sh;
    dir = (dir + 3) % 4;
    if (k < sw + cnt) {
      cout << (y += ("1210"[dir] - '1') * (k - cnt)) + 1 << ' ' << h - x << '\n';
      return;
    }
    y += ("1210"[dir] - '1') * (--sw);
    cnt += sw;
    dir = (dir + 3) % 4;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int w, h, k;
  cin >> w >> h >> k;
  if (k > w * h) cout << 0 << '\n';
  else f(w, h, k);
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}