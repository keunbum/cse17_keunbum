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
    vector<int> deg(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> to[i];
      --to[i];
      ++deg[to[i]];
    }
    vector<int> q;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) {
        q.push_back(i);
      }
    }
    for (int i = 0; i < (int) q.size(); i++) {
      if (--deg[to[q[i]]] == 0) {
        q.push_back(to[q[i]]);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += (deg[i] == 0);
    cout << ans << '\n';
  }
  return 0;
}
