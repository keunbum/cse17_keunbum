#include <iostream>
#include <functional>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, b;
  cin >> a >> b;
  function<long long(long long, long long)> gcd = [&](long long a, long long b) {
    return a == 0 ? b : gcd(b % a, a);
  };
  long long g = gcd(a, b);
  cout << a * b / g << '\n';
  return 0;
}