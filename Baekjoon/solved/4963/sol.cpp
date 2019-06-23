#include <iostream>

using namespace std;

const int N = 56;

bool chk[N][N];
int a[N][N];

void dfs(int x, int y) {
  for (int i = 0; i < 8; i++) {
    int u = x + "22210001"[i] - '1';
    int v = y + "01222100"[i] - '1';
    if (a[u][v] && !chk[u][v]) {
      chk[u][v] = true;
      dfs(u, v);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    int w, h;
    cin >> w >> h;
    if (!w && !h) break;
    fill_n(chk[0], N * N, false);
    fill_n(a[0], N * N, 0);
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        cin >> a[i][j];
      }
    }
    int ans = 0;
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        if (a[i][j] && !chk[i][j]) {
          chk[i][j] = true;
          dfs(i, j);
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}