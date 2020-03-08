#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> to(n);
    for (int i = 0; i < n; i++) {
      cin >> to[i];
      --to[i];
    }
    vector<int> was(n, -1);
    vector<int> st;
    vector<bool> chk(n, false);
    function<void(int v)> Dfs = [&](int v) {
      was[v] = (int) st.size();
      if (was[to[v]] >= 0) {
        st.push_back(v);
        for (int i = was[to[v]]; i < (int) st.size(); i++) {
          chk[st[i]] = true;
        }
        st.pop_back();
      } else
      if (was[to[v]] == -1) {
        st.push_back(v);
        Dfs(to[v]);
        st.pop_back();
      }
      was[v] = -2;
    };
    for (int i = 0; i < n; i++) {
      if (was[i] == -1) Dfs(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += (!chk[i]);
    cout << ans << '\n';
  }
  return 0;
}