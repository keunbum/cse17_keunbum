#include <iostream>
#include <map>

using namespace std;

int p, q;
map<long long, long long> a;

long long dp(long long n) {
  if (a.find(n) != a.end()) return a[n];
  return a[n] = dp(n / p) + dp(n / q);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n >> p >> q;
  a[0] = 1;
  cout << dp(n) << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
