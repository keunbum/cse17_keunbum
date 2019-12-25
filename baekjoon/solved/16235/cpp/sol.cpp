#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nut[12][12];
int tut[12][12];
int ac[12][12];
vector<int> tree[12][12];
vector<int> ttee[12][12];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> ac[i][j];
      nut[i][j] = 5;
    }
  }
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    tree[x][y].push_back(z);
  }
  while (k--) {
    // spring ans summer
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        sort(tree[i][j].begin(), tree[i][j].end());
        ttee[i][j].clear();
        tut[i][j] = 0;
        int nn = tree[i][j].size();
        for (int s = 0; s < nn; s++) {
          if (tree[i][j][s] > nut[i][j]) {
            tut[i][j] += tree[i][j][s] / 2;
          } else {
            nut[i][j] -= tree[i][j][s];
            ttee[i][j].push_back(tree[i][j][s] + 1);
          }
        }
        tree[i][j] = ttee[i][j];
        nut[i][j] += tut[i][j];
      }
    }
    // fall and winter
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        int nn = tree[i][j].size();
        for (int s = 0; s < nn; s++) {
          if (tree[i][j][s] % 5 != 0) continue;
          for (int v = 0; v < 8; v++) {
            int x = i + "00011222"[v] - '1';
            int y = j + "01202012"[v] - '1';
            if (x >= 1 && x <= n && y >= 1 && y <= n) {
              tree[x][y].push_back(1);
            }
          }
        }
        nut[i][j] += ac[i][j];
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans += tree[i][j].size();
    }
  }
  cout << ans << '\n'; 
      
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
