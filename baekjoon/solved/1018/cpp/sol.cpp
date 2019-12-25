#include <iostream>

using namespace std;

bool a[50][50];

inline int count(int h, int w) {
  int ret = 0;
  h -= 8; w -= 8;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if ((i + j + a[i + h][j + w]) & 1) ret++;
    }
  }  
  return min(ret, 64 - ret);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  char c;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> c;
      if (c == 'W') a[i][j] = true;
    }
  }
  int ans = 64;
  for (int i = 8; i <= h; i++) {
    for (int j = 8; j <= w; j++) {
      ans = min(ans, count(i, j));
    }
  }
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}