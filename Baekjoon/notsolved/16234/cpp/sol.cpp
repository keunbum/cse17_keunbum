#include <iostream>
#include <cstring>
#include <numeric>

using namespace std;

int a[50][50];
int rr[12345];
int cnt[12345][2];

int root(int x) {
  return rr[x] == x ? x : (rr[x] = root(rr[x]));
}

inline void print(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cerr << a[i][j];
      cerr << (j == n - 1 ? '\n' : ' ');
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l, r;
  cin >> n >> l >> r;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  print(n);
  while (1) {
    iota(rr, rr + n * n, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i + 1 != n) {
          int t = abs(a[i][j] - a[i + 1][j]);
          if (t >= l && t <= r) {
            rr[root(i * n + j)] = root((i + 1) * n + j);
          }
        }
        if (j + 1 != n) {
          int t = abs(a[i][j] - a[i][j + 1]);
          if (t >= l && t <= r) {
            rr[root(i * n + j)] = root(i * n + j + 1);
          }
        }
      }
    }
    int t;
    for (t = 0; t < n *n; t++) {
      if (rr[t] != t) break;
    }
    if (t >= n * n) break;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int t = root(i * n + j);
        cnt[t][0]++;
        cnt[t][1] += a[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int t = root (i * n + j);
        a[i][j] = cnt[t][1] / cnt[t][0];
      }
    }
    print(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cerr << "rr[" << i * n + j << "] = " << rr[i * n + j];
        cerr << (j == n - 1 ? '\n' : ' ');
      }
    }
    cerr << '\n';
    ans++;
  }
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}