#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e9;

int a[12], b[4];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 4; i++) {
    cin >> b[i];
  }
  int Min = MAX;
  int Max = -MAX;
  function<void(int, int)> Dfs = [&](int v, int val) {
    if (v == n) {
      Min = min(Min, val);
      Max = max(Max, val);
      return;
    }
    for (int i = 0; i < 4; i++) {
      if (b[i] > 0) {
        int nval = val;
        if (i == 0) {
          nval += a[v];
        }
        if (i == 1) {
          nval -= a[v];
        }
        if (i == 2) {
          nval *= a[v];
        }
        if (i == 3) {
          nval /= a[v];
        }
        --b[i];
        Dfs(v + 1, nval);
        ++b[i];
      }
    }
  };
  Dfs(1, a[0]);
  cout << Max << '\n' << Min << '\n';
  return 0;
}
