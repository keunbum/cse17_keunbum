#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = (int) 5e6;
  mt19937 rng(58);
  const int MAXV = (int) 1e9;
  const int L = 1;
  cout << N << ' ' << L << '\n';
  for (int i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << ((rng() % (MAXV + MAXV + 1)) - MAXV);
  }
  cout << '\n';
  return 0;
}
