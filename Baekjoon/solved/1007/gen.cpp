#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  mt19937 rng(58);
  const int C = (int) 1e5;
  auto Get = [&]() {
    int foo = rng() % (C + C + 1);
    return foo - C;
  };
  int tt = 1;
  cout << tt << '\n';
  while (tt--) {
    int n = 20;
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
      cout << Get() << " " << Get() << '\n';
    }
  }
  return 0;
}
