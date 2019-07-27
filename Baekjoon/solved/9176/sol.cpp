#include <iostream>
#include <vector>

using namespace std;

inline bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  for (int i = 7; i < min(k, 60); i++) {
    if (!isPrime(i)) continue;
    long long m = (1LL << i) - 1;
    vector<long long> ans;
    for (long long j = 3; j * j <= m; j += 2) {
      while (m % j == 0) {
        ans.push_back(j);
        m /= j;
      }
    }
    if (m > 1) ans.push_back(m);
    int n = (int) ans.size();
    if (n <= 1) continue;
    for (int i = 0; i < n; i++) {
      if (i) cout << "* ";
      cout << ans[i] << ' ';
    }
    cout << "= " << ((1LL << i) - 1) << " = " << "( 2 ^ " << i << " ) - 1" << '\n';
  }
  return 0;
}