#include <bits/stdc++.h>

using namespace std;

const int N = 1002;

int a[N];
vector<int> g[N * N];
int deg[N * N];
int q[N * N];
int dp[N * N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int INF = (int) 1e9;
  auto T = [&](const char *s) {
    const int A[7] = {9, 11, 0, 2, 4, 5, 7};
    return A[s[0] - 'A'] + 12 * (s[1] - '0') + (int) (s[2] == '#');
  };
  for (int i = 0; i < 2; i++) {
    char s[5];
    cin >> s;
    a[i] = T(s);
  }
  int n;
  cin >> n;
  n += 2;
  for (int i = 2; i < n; i++) {
    char s[5];
    cin >> s;
    a[i] = T(s);
  }
  for (int v = 0; v < n * n; v++) {
    dp[v] = INF;
    int x = v / n;
    int y = v % n;
    if (x == y || y == 0 || x == n - 1 || y == n - 1) {
      continue;
    }
    int z = max(x, y) + 1;
    int ua = z * n + y;
    int ub = x * n + z;
    g[ua].push_back(v);
    g[ub].push_back(v);
    deg[v] += 2;
  }
  int b = 0;
  int e = 0;
  for (int i = 0; i < n * n; i++) {
    if (deg[i] == 0) {
      dp[i] = 0;
      q[e++] = i;
    }
  }
  while (b < e) {
    int from = q[b++];
    for (int to : g[from]) {
      int x = to / n;
      int y = to % n;
      int z = max(x, y) + 1;
      int cost = (z * n + y == from) ? abs(a[x] - a[z]) : abs(a[y] - a[z]);
      dp[to] = min(dp[to], dp[from] + cost);
      if (--deg[to] == 0) {
        q[e++] = to;
      }
    }
  }
  int x = 0;
  int y = 1;
  cout << dp[0 * n + 1] << '\n';
  for (int z = 2; z < n; z++) {
    if (z > 2) {
      cout << ' ';
    }
    int ua = z * n + y;
    int ub = x * n + z;
    if (dp[ua] + abs(a[x] - a[z]) < dp[ub] + abs(a[y] - a[z])) {
      cout << 1;
      x = z;
    } else {
      cout << 2;
      y = z;
    }
  }
  cout << '\n';
  return 0;
}
