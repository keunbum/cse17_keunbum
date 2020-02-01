#include <bits/stdc++.h>

using namespace std;

mt19937 rng(58);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int alpha = 26;
  const int N = 1000;
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < N; i++) {
      char c = rng() % alpha + 'A';
      cout << c;
    }
    cout << '\n';
  }
  return 0;
}
