#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, b;
  cin >> a >> b;
  long long g = __gcd(a, b);
  cout << a * b / g << '\n';
  return 0;
}