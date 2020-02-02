#include <bits/stdc++.h>

using namespace std;

mt19937 rng(58);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 50;
  const int K = 15;
  const int T = 8;
  cout << N << ' ' << K << '\n';
  for (int i = 0; i < N; i++) {
    string s = "anta";
    int n = rng() % T;
    for (int j = 0; j < n; j++) {
      s += rng() % 26 + 'a';
    }
    s += "tica";
    cout << s << '\n';
  }
  return 0;
}
