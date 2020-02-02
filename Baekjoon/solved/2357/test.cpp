#include <bits/stdc++.h>

using namespace std;

mt19937 rng(58);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = (int) 1e5;
  const int M = (int) 5;
  const int MAX = (int) 1e9;
  cout << N << ' ' << M << '\n';
  for (int i = 0; i < N; i++) {
    cout << (rng() % MAX) + 1 << '\n';
  }
  for (int i = 0; i < M; i++) {
    int x = rng() % N + 1;
    int y = rng() % N + 1;
    cout << x << ' ' << y << '\n';
  }
  return 0;
}
