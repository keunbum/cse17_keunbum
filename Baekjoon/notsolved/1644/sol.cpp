#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 4e6;

bool is_c[MAXN + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> primes;
  for (int i = 2; i <= n; i++) {
    if (is_c[i]) {
      continue;
    }
    primes.push_back(i);
    for (int j = i + i; j <= n; j += i) {
      is_c[j] = true;
    }
  }
  int m = (int) primes.size();
  vector<vector<int>> a(m);
  long long ans = 0LL;
  for (int i = 0; i < m; i++) {
    a[i].push_back(primes[i]);
    if (primes[i] == n) {
//      cerr << primes[i] << '\n';
      ans++;
    }
    if (i - 1 < 0) {
      continue;
    }
    for (int x : a[i - 1]) {
      if (x + primes[i] <= n) {
        a[i].push_back(x + primes[i]);
        if (x + primes[i] == n) {
//          cerr << x << ' ' << primes[i] << '\n';
          ans++;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
