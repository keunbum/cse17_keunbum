#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>

using namespace std;

const int md = (int) 1e9 + 7;

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
  int n, k;
  cin >> n >> k;
  const int N = n;
  vector<int> fact(N + 1);
  fact[0] = 1;
  for (int i = 0; i < N; i++) {
    fact[i + 1] = mul(fact[i], i + 1);
  }
  auto C = [&](int n, int k) {
    if (k < 0 || k > n) return 0;
    return mul(fact[n], mul(inv(fact[k]), inv(fact[n - k])));
  };
  cout << C(n, k) << '\n';
//cerr << (float) clock() / CLOCKS_PER_SEC << '\n';
  return 0;
}