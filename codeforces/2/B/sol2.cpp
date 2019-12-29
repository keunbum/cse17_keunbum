#include <iostream>
#include <cstring>

using namespace std;

const int inf = (int) 1e9;
const int N = 1010;

int r[N][N][2];
int f[N][N];
int pr[N][N];

int p[N + N];


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ci = 0;
  int cj = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int foo;
      cin >> foo;
      if (foo == 0) {
        r[i][j][0] = r[i][j][1] = inf;
        ci = i;
        cj = j;
        continue;
      }
      int x = foo;
      while ((x & 1) == 0) {
        r[i][j][0]++;
        x >>= 1;
      }
      x = foo;
      while (x % 5 == 0) {
        r[i][j][1]++;
        x /= 5;
      }
    }
  }
  int ans = inf;
  int kp = 0;
  for (int q = 0; q < 2; q++) {
    memset(f, 0, sizeof(f));
    memset(pr, 0, sizeof(pr));
    f[1][1] = r[1][1][q];
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i + j == 2) {
          continue;
        }
        f[i][j] = r[i][j][q];
        if (i == 1) {
          f[i][j] += f[i][j - 1];
          pr[i][j] = 2;
        } else
        if (j == 1) {
          f[i][j] += f[i - 1][j];
          pr[i][j] = 1;
        } else
        if (f[i - 1][j] < f[i][j - 1]) {
          f[i][j] += f[i - 1][j];
          pr[i][j] = 1;
        } else {
          f[i][j] += f[i][j - 1];
          pr[i][j] = 2;
        }
      }
    }
    if (f[n][n] < ans) {
      ans = f[n][n];
      kp = 0;
      int x = n;
      int y = n;
      while (x + y > 2) {
        kp++;
        p[kp] = pr[x][y];
        if (p[kp] == 1) x--;
        else y--;
      }
    }
  }
  if (ans > 1 && ci > 0) {
    cout << 1 << '\n';
    for (int i = 1; i < ci; i++) cout << 'D';
    for (int i = 1; i < cj; i++) cout << 'R';
    for (int i = ci; i < n; i++) cout << 'D';
    for (int i = cj; i < n; i++) cout << 'R';
    cout << '\n';
  } else {
    cout << ans << '\n';
    for (int i = kp; i >= 1; i--) {
      cout << (p[i] == 1 ? 'D' : 'R');
    }
    cout << '\n';
  }
  return 0;
}
