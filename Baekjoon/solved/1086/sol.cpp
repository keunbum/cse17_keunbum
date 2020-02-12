#include <bits/stdc++.h>

using namespace std;

int md;

struct Mint {
  int x;
  Mint(int _x) {
    x = _x % md;
  }
  Mint(int a, int b) {
    Mint A(a);
    x = 1;
    while (b > 0) {
      if (b & 1) *this = *this * A;
      A = A * A;
      b >>= 1;
    }
  }
  Mint(string& s) {
    x = 0;
    for (int i = 0; i < (int) s.size(); i++) {
      Mint t(s[i] - '0');
      *this = *this * Mint(10) + t;
    }
  }
  Mint operator+(const Mint& o) const {
    int y = x + o.x;
    if (y >= md) y -= md;
    return Mint(y);
  }
  Mint operator*(const Mint& o) const {
    int y = x * o.x;
    y %= md;
    return Mint(y);
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> A(n);
  vector<int> S(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    S[i] = (int) A[i].size();
  }
  cin >> md;
  vector<Mint> a;
  for (int i = 0; i < n; i++) {
    a.emplace_back(A[i]);
  }
  // Do we have to do all the cases one by one?

  int all = 1;
  for (int i = 1; i <= md; i++) {
    all *= i;
  }
  if (cnt == 0) cout << "0/1" << '\n';
  int g = __gcd(cnt, all);
  else cout << cnt / g << '/' << all / g << '\n';
  return 0;
}
