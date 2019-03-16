#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int N = 25;

int n;
string a[N];
bool dic[N][N];
int vx[] = {1, 0, -1, 0}, vy[] = {0, 1, 0, -1};
vector<int> cnt;

void dfs(int x, int y, int d) {
  if (x >= 0 && x < n && y >= 0 && y < n && !dic[x][y]) {
    dic[x][y] = true;
    if (a[x][y] != 0) {
      if (d == 0) {
        cnt.push_back(0);
        d = cnt.size();
      }
      cnt[d - 1]++;
      for (int i = 0; i < 4; i++) {
        dfs(x + vx[i], y + vy[i], d);
      }
    }
  }
}

void solve() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dfs(i, j, 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < n; j++)
      a[i][j] -= '0';
  }
  solve();
  n = cnt.size();
  cout << n << '\n';
  sort(cnt.begin(), cnt.begin() + n);
  for (int i = 0; i < n; i++)
    cout << cnt[i] << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}