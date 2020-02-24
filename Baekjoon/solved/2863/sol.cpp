#include <bits/stdc++.h>

using namespace std;

struct Fraction {
  int x;
  int y;
  Fraction() : x(0), y(1) {}
  Fraction(int a, int b, int c, int d) {
    x = a * d + b * c;
    y = c * d;
  }
  bool operator<(const Fraction& o) const {
    return x * o.y < o.x * y;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<Fraction> f;
  f.emplace_back(a, b, c, d);
  f.emplace_back(c, a, d, b);
  f.emplace_back(d, c, b, a);
  f.emplace_back(b, d, a, c);
  cout << (int) (max_element(f.begin(), f.end()) - f.begin()) << '\n';
  return 0;
}
