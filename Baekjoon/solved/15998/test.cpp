#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  mt19937 rng(58);
  const int N = (int) 3e5;
  cout << N << '\n';
  const long long C = (long long) 1e18;
  const long long M = (long long) 9e18;
  long long money = 0LL;
  for (int i = 0; i < N; i++) {
    /*
    long long A = rng() % (C + C + 1) - C / (long long) 1e9;
    long long B = 0LL;
    if (money + A < 0) {
      long long q = 1;
      while (money + A + M * q < 0) ++q;
      B = money + A + M * q;
    } else {
      B = money + A;
    }
    cout << A << ' ' << B << '\n';
    */
    long long A = -1e18;
    long long B = 0;
    cout << A << ' ' << B << '\n';
    money = B;
  }
  return 0;
}