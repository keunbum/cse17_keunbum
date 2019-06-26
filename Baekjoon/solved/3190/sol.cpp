#include <iostream>

using namespace std;

char rot[12345];
int a[123][123];
int x[12345], y[12345];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  while (k--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    a[x][y] = 1; // apple
  }
  cin >> k;
  while (k--) {
    int t;
    cin >> t >> rot[t];
  }
  int u = 0, v = 0;
  int t = 1;
  int dir = 1;
  int b = 0;
  a[u][v] = -1;
  while (true) {
    u += "2101"[dir] - '1';
    v += "1210"[dir] - '1';
    if (u < 0 || u >= n || v < 0 || v >= n || a[u][v] < 0) break;
    if (!a[u][v]) { // not apple
      a[x[b]][y[b]] = 0;
      b++;
    }
    a[u][v] = -1;
    x[t] = u; y[t] = v;
    if (rot[t] == 'L') dir = (dir + 1) & 3;
    if (rot[t] == 'D') dir = (dir + 3) & 3;
    t++;
  }
  cout << t  << '\n';
  return 0;
}