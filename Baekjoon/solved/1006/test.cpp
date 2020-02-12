#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int seed = 58;
  if (argc == 2) seed = atoi(argv[1]);
  mt19937 rng(seed);
  int T = 1;
  cout << T << '\n';
  for (int Q = 1; Q <= T; Q++) {
    int N = (int) 1e4;
    int W = (int) 1e4;
    int MAX = W;
    cout << N << ' ' << W << '\n';
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < N; j++) {
        if (j > 0) cout << ' ';
        cout << rng() % MAX + 1;
      }
      cout << '\n';
    }
  }
  return 0;
}
