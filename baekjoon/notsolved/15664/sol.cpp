#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n, m;
int a[8], g[8];
set<vector<int>> s;

void dfs(int v, int pos) {
  if (v == m) {
    s.insert(vector<int>(g, g + m));
    return;
  }
  for (int i = pos; i < n; i++) {
    g[v] = a[i];
    dfs(v + 1, i + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  dfs(0, 0);
  for (auto &x : s) {
    int sz = (int) x.size();
    for (int i = 0; i < sz; i++) {
      cout << (i ? " " : "") << x[i];
    }
    cout << '\n';
  }
  return 0;
}