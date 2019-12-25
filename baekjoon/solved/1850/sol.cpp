#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
  return (a == 0) ? b : gcd(b % a, a);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, b;
  cin >> a >> b;
  long long g = gcd(a, b);
  while (g--) cout << '1';
  cout << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}