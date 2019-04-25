#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int g[20]; // generation
pair<int, int> p[20]; // start point
vector<int> d[20]; // direction

bool a[101][101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int dir;
    cin >> p[i].second >> p[i].first >> dir >> g[i];
    d[i].push_back(dir);
    pair<int, int> c(p[i]);
    a[c.first][c.second] = true;
    // generate
    for (int j = 0; j < g[i]; j++) {
      vector<int> t(d[i]);
      int s = d[i].size();
      for (int k = s - 1; k >= 0; k--) {
        t.push_back((d[i][k] + 1) % 4);
      }
      d[i] = t;
    }
    // pointing
    int nn = d[i].size();
    for (int j = 0; j < nn; j++) {
      c.first += "1012"[d[i][j]] - '1'; // x
      c.second += "2101"[d[i][j]] - '1'; // y
      a[c.first][c.second] = true;
    }
  }
  int ans = 0;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (a[i][j] && a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1]) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
