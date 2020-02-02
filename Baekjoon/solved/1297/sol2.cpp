#include <iostream>
#include <functional>

using namespace std;

template <typename T>
inline T P2(T x) { return x * x; }

struct Fraction {
  long long x;
  long long y;
  Fraction(long long _x, long long _y) : x(_x), y(_y) {}
  bool operator<(Fraction& o) const {
    return x * o.y < y * o.x;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long l, a, b;
  cin >> l >> a >> b;
  Fraction x(P2(l * a), P2(a) + P2(b));
  Fraction y(P2(l * b), P2(a) + P2(b));
  auto Find = [&](Fraction& f) {
    long long res = 0;
    for (long long i = 0; i <= 1000; i++) {
      Fraction foo(i * i, 1LL);
      if (f < foo) {
        res = i - 1;
        break;
      }
    }
    return res;
  };
  cout << Find(x) << ' ' << Find(y) << '\n';
  return 0;
}
