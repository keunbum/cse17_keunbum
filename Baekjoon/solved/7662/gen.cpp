#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  cout << T << '\n';
  int K = (int) 1e6;
  cout << K << '\n';
  int MAX = (int) 2e9;
  mt19937 rng(58);
  for (int i = 0; i < K; i++) {
    int t = rng() % 2;
    if (t == 0) {
      cout << "I " << (rng() % MAX) << '\n';
    } else {
      cout << "D " << ((rng() % 2) ? "1" : "-1") << '\n';
    }
  }
  return 0;
}
