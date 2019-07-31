#include <iostream>
#include <vector>

using namespace std;

const int N = 1001;

int T[N], M[N], deg[N], ans[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      M[i] = deg[i] = ans[i] = 0;
      cin >> T[i];
    }
    vector<vector<int>> g(n + 1);
    while (m--) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      deg[y]++;
      M[y] = max(M[y], T[x]); 
    }
    int w;
    cin >> w;
    vector<int> q;
    for (int i = 1; i <= n; i++) {
      if (deg[i] == 0) {
        ans[i] = T[i];
        q.push_back(i);
      }
    }
    for (int i = 0; i < (int) q.size(); i++) {
      int v = q[i];
      for (int to : g[v]) {
        ans[to] = max(ans[to], ans[v]); 
        if (--deg[to] == 0) {
          ans[to] += T[to];
          q.push_back(to);
        }
      }
    }
    cout << ans[w] << '\n';
  }
  return 0;
}                                       	