#include <iostream>
#include <cassert>

const int md = (int) 1e9 + 7;

using namespace std;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}

inline int inv(int a) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m;
  cin >> m;
  int ans = 0;
  while (m--) {
    int n, s;
    cin >> n >> s;
    s = mul(s, inv(n));
    add(ans, s);
  }
  cout << ans << '\n';
  return 0;
}