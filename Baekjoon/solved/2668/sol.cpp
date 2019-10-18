#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> ans;
  vector<bool> chk(n + 1, false);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i == a[i]) {
      chk[i] = true;
      ans.push_back(i);
    }
  }
  bitset<101> A, B;
  int iter = 0;
  vector<int> was(n + 1, 0);
  function<void(int)> Dfs = [&](int v) {
    was[v] = iter;
    A.set(v, 1);
    B.set(a[v], 1);
    if (!chk[v] && was[a[v]] != iter) {
      Dfs(a[v]);
    } else
    if (A == B) {
      for (int i = 1; i < 101; i++) {
        if (A.test(i)) {
          chk[i] = true;
          ans.push_back(i);
        }
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    iter++;
    if (!chk[i]) {
      A.reset();
      B.reset();
      Dfs(i);
    }
  }
  int sz = (int) ans.size();
  cout << sz << '\n';
  sort(ans.begin(), ans.end());
  for (int i = 0; i < sz; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
