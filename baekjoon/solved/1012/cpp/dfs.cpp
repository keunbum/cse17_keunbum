#include <iostream>
#include <cstring>

using namespace std;

int vx[] = {1, 0, -1, 0}, vy[] = {0, 1, 0, -1};

int cnt;
bool chk[50][50];
int a[50][50];

void dfs(int h, int w, int x, int y, bool f) {
  if (x < 0 || x >= h || y < 0 || y >= w || a[x][y] == 0 || chk[x][y])
    return;
  chk[x][y] = true;
  if (f) cnt++;
  for (int i = 0; i < 4; i++) {
    dfs(h, w, x + vx[i], y + vy[i], false);
  }
}

void solve(int h, int w) {
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      dfs(h, w, i, j, true);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    int w, h, n;
    cin >> w >> h >> n;
    memset(a, 0, sizeof(a));
    memset(chk, false, sizeof(chk));
    cnt = 0;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> y >> x;
      a[x][y] = 1;
    }
    solve(h, w);
    cout << cnt << '\n';      
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
