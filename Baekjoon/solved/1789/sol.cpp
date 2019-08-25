#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  double ans = (-1 + sqrt(1 + 8 * n)) * 0.5;
  cout << (int) ans << '\n';
  return 0;
}
