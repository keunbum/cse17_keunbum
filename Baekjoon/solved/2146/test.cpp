#include <bits/stdc++.h>

using namespace std;

mt19937 rng(58);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int n = 100;
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j > 0) cout << ' ';
      cout << 0 % 2;
    }
    cout << '\n';
  }
  return 0;
}
