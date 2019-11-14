#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int inf = (int) 1e9;
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    while (t--) {
      int j;
      cin >> j;
      j--;
      g[i].push_back(j);
    }
  }
  int ans = inf;
  for (int t = 1; t < (1 << n) - 1; t++) {
    set<int> a, b;
    for (int i = 0; i < n; i++) {
      if (t & (1 << i)) {
        a.insert(i);
      } else {
        b.insert(i);
      }
    }
//    debug(a);
//    debug(b);
    set<int> A(a), B(b);
    vector<bool> was(n);
    int q[100];
    auto RunBfs = [&](int s, set<int>& a, set<int>& A) {
      fill(was.begin(), was.end(), false);
      int b = 0, e = 1;
      q[0] = s;
      A.erase(s);
      was[q[b]] = true;
      while (b < e) {
        for (int to : g[q[b]]) {
          if (a.count(to) && !was[to]) {
            was[q[b]] = true;
            q[e] = to;
            A.erase(to);
            ++e;
          }
        }
        ++b;
      }
    };
    RunBfs(*a.begin(), a, A);
    RunBfs(*b.begin(), b, B);
    auto F = [&](int x, int y) {
      return x + p[y];
    };
//    debug(A);
//    debug(B);
    if (A.empty() && B.empty()) {
      ans = min(ans, abs(accumulate(a.begin(), a.end(), 0, F) - accumulate(b.begin(), b.end(), 0, F)));
    }
  }
  cout << (ans == inf ? -1 : ans) << '\n';
  return 0;
}
