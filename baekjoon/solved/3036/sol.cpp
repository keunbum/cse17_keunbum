#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int nu;
  cin >> nu;
  for (int i = 1; i < n; i++) {
    int t;
    cin >> t;
    int g = __gcd(nu, t);
    cout << nu / g << '/' << t / g << '\n';
  }
  return 0;
}