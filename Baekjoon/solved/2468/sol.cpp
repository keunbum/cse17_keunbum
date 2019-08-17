#include <bits/stdc++.h>

using namespace std;

const int N = 123;

const int DX[2] = {0, 1};
const int DY[2] = {1, 0};

int a[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  vector<int> p(n * n);
  function<int(int)> Get = [&](int v) {
    return v == p[v] ? v : p[v] = Get(p[v]);
  };
  for (int h = 0; h <= 100; h++) {
    iota(p.begin(), p.end(), 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] <= h) {
          p[i * n + j] = -1;
          continue;
        }
        for (int k = 0; k < 2; k++) {
          int x = i + DX[k];
          int y = j + DY[k];
          if (x >= 0 && x < n && y >= 0 && y < n && a[x][y] > h) {
            p[Get(x * n + y)] = Get(i * n + j);
          }
        }
      }
    }
    vector<bool> chk(n * n, false);
    int cnt = 0;
    for (int i = 0; i < n * n; i++) {
      if (p[i] == -1) {
        continue;
      }
      int id = Get(i);
      if (!chk[id]) {
        chk[id] = true;
        cnt++;
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << '\n';
  return 0;
}
