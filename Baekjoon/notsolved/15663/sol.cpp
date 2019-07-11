#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
vector<int> a, g;
vector<bool> chk;
set<vector<int>> s;

void dfs(int v) {
  if (v == m) {
    s.insert(g);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (chk[i]) continue;
    chk[i] = true;
    g.push_back(a[i]);
    dfs(v + 1);
    g.pop_back();
    chk[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  a.resize(n);
  chk.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  dfs(0);
  for (auto &x : s) {
    n = (int) x.size();
    for (int i = 0; i < n; i++) {
      cout << (i ? " " : "") << x[i];
    }
    cout << '\n';
  }
  return 0;
}