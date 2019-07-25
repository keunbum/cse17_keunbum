#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

const int N = 50;
const int inf = (int) 1e9;

int iter;
int r, c;
int n, m;
string a[N];
int b[N][N];
vector<int> pa, pb, was;
vector<pair<int, int>> C;
vector<vector<int>> dis;
map<pair<int, int>, int> M;

void bfs(int v) {
  vector<pair<int, int>> q(N * N);
  fill_n(b[0], N * N, -1);
  q[0] = C[v];
  b[C[v].first][C[v].second] = 0;
  int beg = 0, end = 1;
  while (beg < end) {
    int x = q[beg].first;
    int y = q[beg++].second;
    if (a[x][y] == 'P') {
      dis[v][M[make_pair(x, y)]] = b[x][y];
    }
    for (int i = 0; i < 4; i++) {
      int u = x + "2101"[i] - '1';
      int v = y + "1210"[i] - '1';
      if (u < 0 || u >= r || v < 0 || v >= c || a[u][v] == 'X' || b[u][v] >= 0) continue;
      b[u][v] = b[x][y] + 1;
      q[end++] = make_pair(u, v);
    }
  }
}

bool dfs(int v, int limit) {
  was[v] = iter;
  for (int u = 0; u < m; u++) {
    if (dis[v][u] <= limit && pb[u] == -1) {
      pa[v] = u;
      pb[u] = v;
      return true;
    }
  }
  for (int u = 0; u < m; u++) {
    if (dis[v][u] <= limit && was[pb[u]] != iter && dfs(pb[u], limit)) {
      pa[v] = u;
      pb[u] = v;
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    cin >> a[i];
    for (int j = 0; j < c; j++) {
      char t = a[i][j];
      if (t == 'C') {
        n++;
        C.emplace_back(i, j);
      } else
      if (t == 'P') {
        M[make_pair(i, j)] = m++;
      }
    }
  }
  if (n > m) { cout << -1 << '\n'; return 0; }
  if (n == 0) { cout << 0 << '\n'; return 0; }
  pa.resize(n);
  pb.resize(m);
  was.resize(n);
  dis.resize(n, vector<int>(m, inf));
  for (int i = 0; i < n; i++) {
    bfs(i);
  }
  int low = 0, high = r * c;
  while (low < high) {
    fill_n(pa.begin(), n, -1);
    fill_n(pb.begin(), m, -1);
    fill_n(was.begin(), n, 0);
    int flow = 0;
    int mid = (low + high) / 2;
    iter = 0;
    while (true) {
      iter++;
      int add = 0;
      for (int i = 0; i < n; i++) {
        if (pa[i] == -1) {
          add += (int) dfs(i, mid);
        }
      }
      if (add == 0) break;
      flow += add;
    }
    if (flow == n) high = mid;
    else low = mid + 1;
  }                     
  int ans = (low + high) / 2;
  cout << (ans == r * c ? -1 : ans) << '\n';
  return 0;
}