#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int w, h, n, k;
  cin >> w >> h >> n >> k;
  vector<int> p(n);
  vector<int> q(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i] >> q[i];
  }
  auto IsIn = [&](int a, int x, int b) {
    return a <= x && x <= b;
  };
  int ans = 0;
  int ans_x = -1;
  int ans_y = -1;
  auto Update = [&](int a, int b) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (IsIn(a, p[i] + q[i], a + k) && IsIn(b, p[i] - q[i], b + k)) {
        ++cnt;
      }
    }
    if (cnt > ans) {
      ans = cnt;
      ans_x = (a + b) / 2 + k / 2;
      ans_y = (a - b) / 2;
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a = p[i] + q[i];
      int b = p[j] - q[j];
      if ((a + b) & 1) {
        Update(a, b - 1);
        Update(a, b + 1);
      } else {
        Update(a, b);
      }
    }
  }
  cout << ans_x << ' ' << ans_y << '\n' << ans << '\n';
  return 0;
}
