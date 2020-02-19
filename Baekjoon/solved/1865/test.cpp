#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  mt19937 rng(58);
  auto Get = [&](int x) { // 0 ~ x-1
    return rng() % x;
  };
  int T = 5;
  cout << T << '\n';
  while (T--) {
    const int N = 500;
    int M = 2500;
    int W = 200;
    const int MAXT = (int) 1e4;
    cout << N << ' ' << M << ' ' << W << '\n';
    while (M--) {
      int x = Get(N) + 1;
      int y = Get(N) + 1;
      while (x == y) {
        y = Get(N) + 1;
      }
      int z = Get(MAXT) + 1;
      cout << x << ' ' << y << ' ' << z << '\n';
    }
    while (W--) {
      int x = Get(N) + 1;
      int y = Get(N) + 1;
      while (x == y) {
        y = Get(N) + 1;
      }
      int z = Get(MAXT) + 1;
      cout << x << ' ' << y << ' ' << z << '\n';
    }
  }
  return 0;
}
