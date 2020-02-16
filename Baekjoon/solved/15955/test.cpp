#include <bits/stdc++.h>

using namespace std;

mt19937 rng(12348971398143LL);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 250000;
  const int T = 250000;
  const int MAX = (int) 1e9;
  const int X = MAX / 100;
  cout << N << ' ' << T << '\n';
  for (int i = 0; i < N; i++) {
    int x = (rng() % (MAX + MAX + 1)) - MAX;
    int y = (rng() % (MAX + MAX + 1)) - MAX;
    cout << x << ' ' << y << '\n';
  }
  for (int Q = 1; Q <= T; Q++) {
    while (true) {
      int a = (rng() % N) + 1;
      int b = (rng() % N) + 1;
      int x = rng() % (X + 1);
      if (a != b) {
        cout << a << ' ' << b << ' ' << x << '\n';
        break;
      }
    }
  }
  return 0;
}
