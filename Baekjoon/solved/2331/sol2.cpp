#include <bits/stdc++.h>

using namespace std;

inline int P(int x, int p) {
  int res = 1;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, p;
  cin >> a >> p;
  map<int, int> was;
  int cnt = 0;
  int ans = -1;
  while (true) {
    was[a] = cnt++;
    int u = 0;
    while (a > 0) {
      u += P(a % 10, p);
      a /= 10;
    }
    if (was.find(u) != was.end()) {
      ans = was[u];
      break;
    }
    a = u;
  }
  cout << ans << '\n';
  return 0;
}
