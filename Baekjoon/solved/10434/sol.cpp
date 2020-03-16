#include <bits/stdc++.h>

using namespace std;

inline bool IsPrime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int qq, m;
    cin >> qq >> m;
    cout << qq << ' ' << m;
    int n = m;
    set<int> was;
    was.insert(n);
    do {
      int t = 0;
      while (n > 0) {
        t += (n % 10) * (n % 10);
        n /= 10;
      }
      n = t;
    } while (was.insert(n).second);
    cout << ' ' << (IsPrime(m) && n == 1 ? "YES" : "NO") << '\n';
  }
  return 0;
}
