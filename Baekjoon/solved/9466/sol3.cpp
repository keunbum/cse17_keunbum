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
    int ans = 0;
    vector<int> was(n, -1);
    int iter = 0;
    for (int i = 0; i < n; i++) {
      if (was[i] >= 0) {
        continue;
      }
      int v = i;
      was[v] = iter++;
      vector<int> st;
      st.push_back(v);
      while (was[to[v]] == -1) {
        was[to[v]] = was[v];
        v = to[v];
        st.push_back(v);
      }
      if (was[i] == was[to[v]]) {
        while (true) {
          int u = st.back();
          st.pop_back();
          if (u == to[v]) {
            break;
          }
        }
      }
      ans += (int) st.size();
    }
    cout << ans << '\n';
  }
  return 0;
}
