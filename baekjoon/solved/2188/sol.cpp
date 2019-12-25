#include <iostream>
#include <vector>

using namespace std;

int iter = 0;
vector<vector<int>> a;
vector<int> pa, pb, was;

bool dfs(int v) {
  was[v] = iter;
  for (int u : a[v]) {
    if (pb[u] == -1) {
      pa[v] = u;
      pb[u] = v;
      return true;
    }
  }
  for (int u : a[v]) {
    if (was[pb[u]] != iter && dfs(pb[u])) {
      pa[v] = u;
      pb[u] = v;
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  a.resize(n);
  pa.resize(n, -1);
  pb.resize(m, -1);
  was.resize(n, 0);
  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    while (s--) {
      int foo;
      cin >> foo;
      foo--;
      a[i].push_back(foo);
    }
  }
  int ans = 0;
  while (true) {
    iter++;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (pa[i] == -1 && dfs(i)) {
        cnt++;
      }
    }
    if (cnt == 0) {
      break;
    }
    ans += cnt;
  }
  cout << ans << '\n';
  return 0;
}