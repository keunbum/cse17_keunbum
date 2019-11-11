#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x, y, z;
  cin >> x >> y >> z;
  int A = a + b;
  int B = c + d;
  auto F = [&](int x) {
    int Ra = x % A;
    int Rb = x % B;
    int res = (int) (Ra > 0 && Ra <= a) + (int) (Rb > 0 && Rb <= c);
    return res;
  };
  cout << F(x) << '\n' << F(y) << '\n' << F(z) << '\n';
  return 0;
}
