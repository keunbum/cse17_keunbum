#include <bits/stdc++.h>

using namespace std;

mt19937 rng(58);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int K = 30;
  const int W = 200;
  const int H = 200;
  cout << K << '\n' << W << ' ' << H << '\n';
  vector<vector<int>> a(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      a[i][j] = rng() % 2;
    }
  }
  a[0][0] = a[H - 1][W - 1] = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (j > 0) {
        cout << ' ';
      }
      cout << a[i][j];
    }
    cout << '\n';
  }
  return 0;
}
