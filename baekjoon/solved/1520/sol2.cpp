#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 567;

int a[N][N], ans[N][N];
vector<pair<int, pair<int, int>>> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
      v.emplace_back(a[i][j], make_pair(i, j));
    }
  }
  sort(v.rbegin(), v.rend());
  ans[1][1] = 1;
  for (auto &t : v) {
    int f = t.second.first;
    int g = t.second.second;
    for (int i = 0; i < 4; i++) {
      int x = f + "2101"[i] - '1';
      int y = g + "1210"[i] - '1';
      if (a[f][g] < a[x][y]) {
        ans[f][g] += ans[x][y];
      }
    }
  }
  cout << ans[h][w] << '\n';
  return 0;
}