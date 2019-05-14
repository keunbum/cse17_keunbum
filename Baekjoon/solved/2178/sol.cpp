#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 2, vector<int> (m + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  }
  vector<pair<int, int>> que;
  que.emplace_back(1, 1);
  a[1][1] = 2;
  for (int i = 0; i < (int) que.size(); i++) {
    int cx = que[i].first;
    int cy = que[i].second;
    if (a[cx][cy] == a[n][m]) break;
    for (int j = 0; j < 4; j++) {
      int x = cx + "2101"[j] - '1';
      int y = cy + "1210"[j] - '1';
      if (a[x][y] != 1) continue;
      a[x][y] = a[cx][cy] + 1;
      que.emplace_back(x, y);
    }
  }
  cout << a[n][m] - 1 << '\n';
  return 0;
}