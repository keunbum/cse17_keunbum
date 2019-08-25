#include <bits/stdc++.h>

using namespace std;

inline bool IsIn(int a, int b, int c) {
  return b <= a && a <= c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int W, H, N, K;
  cin >> W >> H >> N >> K;
  vector<pair<int, int>> cuts;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    cuts.emplace_back(x - y, x + y);
  }
  int ans = 0;
  int ans_x = -1;
  int ans_y = -1;
  auto Cnt = [&](int cx, int cy) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      if (IsIn(cuts[i].first, cx, cx + K) && IsIn(cuts[i].second, cy, cy + K)) {
        cnt++;
      }
    }
    if (cnt > ans) {
      ans = cnt;
      ans_x = (cx + cy) / 2 + K / 2;
      ans_y = (cy - cx) / 2;
    } 
  };
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int cx = cuts[i].first;
      int cy = cuts[j].second;
      if ((cx + cy) & 1) {
        Cnt(cx, cy + 1);
      }
      Cnt(cx, cy);
    }
  }
  cout << ans_x << ' ' << ans_y << '\n';
  cout << ans << '\n';
  return 0;
}
