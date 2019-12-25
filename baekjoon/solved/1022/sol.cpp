#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

int a[50][5];

int getl(int n) {
  int res = 0;
  while (n /= 10) {
    res++;
  }
  return res;
}

inline int get(int x, int y) {
  int u, v = max(abs(x), abs(y));
  u = x < y ? v + v - x - y : x + y + v * 6;
  v += v - 1;
  return u + v * v;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int xa, ya, xb, yb;
  cin >> xa >> ya >> xb >> yb;
  int mx = 0;
  xb -= xa; yb -= ya;
  for (int i = 0; i <= xb; i++) {
    for (int j = 0; j <= yb; j++) {
      a[i][j] = get(i + xa, j + ya);
      mx = max(mx, a[i][j]);
    }
  }
  int l = getl(mx);
  for (int i = 0; i <= xb; i++) {
    for (int j = 0; j <= yb; j++) {
      cout << string(l - getl(a[i][j]) + 1 * (j > 0), ' ');
      cout << a[i][j];
    }
    cout << '\n';
  }
  return 0;
}