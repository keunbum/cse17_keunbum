#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  mt19937 rng(58);
  const int N = 20;
  cout << N << '\n';
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j > 0) {
        cout << ' ';
      }
      cout << 1;
    }
    cout << '\n';
  }
  return 0;
}
