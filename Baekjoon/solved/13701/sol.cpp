#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 25;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  bitset<N> s;
  int x;
  while (cin >> x) {
    if (s[x] == 0) {
      cout << x << ' ';
    }
    s[x] = 1;
  }
  cout << '\n';
  return 0;
}
