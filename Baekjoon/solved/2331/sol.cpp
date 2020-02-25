#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, p;
  cin >> a >> p;
  auto P = [&](int x) {
    int res = 1;
    for (int i = 0; i < p; i++) {
      res *= x;
    }
    return res;
  };
  map<int, int> was;
  int cnt = 0;
  function<void(int)> Dfs = [&](int v) {
//    cerr << "v = " << v << '\n';
    was[v] = cnt++;
    int u = 0;
    while (v > 0) {
      u += P(v % 10);
      v /= 10;
    }
    if (was.find(u) != was.end()) {
      cout << was[u] << '\n';
      exit(0);
    }
    Dfs(u);
  };
  Dfs(a);
  return 0;
}
