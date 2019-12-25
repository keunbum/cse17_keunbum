#include <iostream>

using namespace std;

int gcd(int a, int b) {
  return a == 0 ? b : gcd(b % a, a);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  int g = gcd(a, b);
  cout << 1LL * a / g * b << '\n';
  return 0;
}