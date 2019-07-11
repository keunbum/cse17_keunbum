#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
int a[8], g[8];
set<vector<int>> s;

void dfs(int v, int bits) {
  if (v == m) {
    s.insert(vector<int>(g, g + m));
    return;
  }
  for (int i = 0; i < n; i++) {
    if (bits & (1 << i)) continue;
    g[v] = a[i];
    dfs(v + 1, bits | (1 << i));
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