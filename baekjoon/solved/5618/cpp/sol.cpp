#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int gcd(int x, int y) {
  return x == 0 ? y : gcd(y % x, x);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, t, g;
  cin >> n >> g;
  for (int i = 1; i < n; i++) {
    cin >> t;
    g = gcd(g, t);
  }
  vector<int> a;
  for (int i = 1; i * i <= g; i++) {
    if (g % i == 0) {
      a.push_back(i);
      if (i * i != g) a.push_back(g / i);
    }
  }
  sort(a.begin(), a.end());
  n = a.size();
  for (int i = 0; i < n; i++)
    cout << a[i] << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
