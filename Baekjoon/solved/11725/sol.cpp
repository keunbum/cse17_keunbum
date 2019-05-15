#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> a;
vector<int> ans;

void dfs(int p) {
  for (int i : a[p]) {
    if (ans[i]) continue;
    ans[i] = p;
    dfs(i);
  }
}

void solve(int n) {
  dfs(n);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  a.resize(n + 1);
  ans.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int foo, bar;
    cin >> foo >> bar;
    a[foo].push_back(bar);
    a[bar].push_back(foo);
  }
  solve(1);
  for (int i = 2; i <= n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}