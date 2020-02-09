#include <bits/stdc++.h>

using namespace std;

struct St {
  bool operator()(const pair<long long, long long>& a, const pair<long long, long long>& b) {
    return a.second > b.second;
  }
};

inline long long Power(long long a, int b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  if (n == 1) { cout << 0 << '\n'; return 0; }
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, St> s;
  s.push({n, 0});
  long long ans = n - 1;
  map<long long, long long> D;
  D[n] = 0;
  while (!s.empty()) {
    long long i, dist;
    tie(i, dist) = s.top();
    s.pop();
    if (dist != D[i]) {
      continue;
    }
    if (i == 1) {
      ans = dist - 1;
      break;
    }
    for (int q = 2; q <= 60; q++) {
      double p = pow(i, 1.0 / q);
      long long nn = (long long) (p + 0.5);
      long long cost = abs(Power(nn, q) - i);
      if (D.count(nn) == 0 || dist + cost + 1 < D[nn]) {  
        D[nn] = dist + cost + 1;
        s.push({nn, dist + cost + 1});
      }
    }
  }
  assert(ans != n - 1);
  cout << ans << '\n';
  return 0;
}
