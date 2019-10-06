#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

struct St {
  pair<int, int> x, y;
};

inline int Dis(pair<int, int>& p, pair<int, int>& q) {
  return abs(p.first - q.first) + abs(p.second - q.second);
}

St st[N][2];
pair<int, int> a[N];
int dp[N][2];
int A[N], B[N], T[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  st[0][0].x = st[0][1].x = {1, 1};
  st[0][0].y = st[0][1].y = {m, m};
  for (int i = 1; i <= n; i++) {
    int da = Dis(st[i - 1][0].x, a[i]);
    int db = Dis(st[i - 1][1].x, a[i]);
    int dc = Dis(st[i - 1][0].y, a[i]);
    int dd = Dis(st[i - 1][1].y, a[i]);
    st[i][0].x = st[i][1].y = a[i];
    A[i] = 1; B[i] = 2;
    for (int j = 1; j < i; j++) {
      T[j] = A[j];
    }
    if (dp[i - 1][0] + da < dp[i - 1][1] + db) {
      dp[i][0] = dp[i - 1][0] + da;
      st[i][0].y = st[i - 1][0].y;
    } else {
      dp[i][0] = dp[i - 1][1] + db;
      st[i][0].y = st[i - 1][1].y;
      for (int j = 1; j < i; j++) {
        A[j] = B[j];
      }
    }
    if (dp[i - 1][0] + dc < dp[i - 1][1] + dd) {
      dp[i][1] = dp[i - 1][0] + dc;
      st[i][1].x = st[i - 1][0].x;
      for (int j = 1; j < i; j++) {
        B[j] = T[j];
      }
    } else {
      dp[i][1] = dp[i - 1][1] + dd;
      st[i][1].x = st[i - 1][1].x;
    }
  }
  cout << min(dp[n][0], dp[n][1]) << '\n';
  int *ans = dp[n][0] < dp[n][1] ? A : B;
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
