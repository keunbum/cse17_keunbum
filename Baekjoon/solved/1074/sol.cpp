#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, r, c;
  cin >> n >> r >> c;
  int cnt = 0;
  function<void(int, int, int)> Rec = [&](int n, int x, int y) {
    if (n == 0) {
      cout << cnt << '\n';
      exit(0);
    }
    int N = (1 << n);
    int sx = x + N / 2;
    int sy = y + N / 2;
    int add = N * N / 4;
    if (r < sx) {
      if (c < sy) {
        Rec(n - 1, x, y);
      } else {
        cnt += add;
        Rec(n - 1, x, sy);
      }
    } else {
      if (c < sy) {
        cnt += add * 2;
        Rec(n - 1, sx, y);
      } else {
        cnt += add * 3;
        Rec(n - 1, sx, sy);
      }
    }
  };
  Rec(n, 0, 0);
  return 0;
}
