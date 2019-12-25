#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int R, B;
  cin >> R >> B;
  int S = R + B;
  int L, W = 0;
  for (L = 3; ; L++) {
    if (S % L == 0) {
      W = S / L;
      if (W != (R / 2 + 2 - L)) continue;
      break;
    }
  }
  cout << W << ' ' << L << '\n';
  return 0;
}