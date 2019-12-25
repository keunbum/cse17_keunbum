#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> c[50];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int r = -1;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    if (p != -1) {
      c[p].push_back(i);
    } else {
      r = i;
    }
  }
  int ans = 0;
  int e;
  cin >> e;
  function<void(int n)> dfs = [&](int v) {
    int sz = (int) c[v].size();
    if (sz == 0) { ans++; return; }
    for (int ch : c[v]) {
      if (ch != e) dfs(ch); else
      if (sz == 1) ans++;
    }
  };
  auto solve = [&](int v) {
    if (v != e) dfs(v);
  };
  solve(r);
  cout << ans << '\n';
  return 0;
}