#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5;

int a[N + 1], q[N + 1], ans[N + 1];
bool was[N + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fill_n(a, N + 1, N);
  int st, en;
  cin >> st >> en;
  int b = 0, e = 0;
  q[e++] = st;
  a[st] = 0;
  ans[st] = 1;
  while (b < e) {
    int v = q[b++];
    if (v == en) {
      break;
    }
    for (int i = -1; i <= 1; i++) {
      int u = v + i + v * (!i);
      if (u >= 0 && u <= N && a[u] >= a[v] + 1) {
        a[u] = a[v] + 1;
        ans[u] += ans[v];
        if (!was[u]) {
          was[u] = true;
          q[e++] = u;
        }
      }
    }
  }
  cout << a[en] << '\n' << ans[en] << '\n';
  return 0;
}
