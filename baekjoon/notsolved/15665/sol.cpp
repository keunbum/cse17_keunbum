#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
int a[7];
vector<int> g;
set<vector<int>> s;

void dfs(int v) {
  if (v == m) {
    s.insert(g);
    return;
  }
  for (int i = 0; i < n; i++) {
    g.push_back(a[i]);
    dfs(v + 1);
    g.pop_back();
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
  dfs(0);
  for (auto &v : s) {
    int sz = (int) v.size();
    for (int i = 0; i < sz; i++) {
      cout << (i ? " " : "") << v[i];
    }
    cout << '\n';
  }
  return 0;
}